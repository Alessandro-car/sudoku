#include "gestire_menu_principale.h"

void iniziare_partita(stringa* partite_salvate) {
	bool_t uscito;
	char comando_utente;
	int difficolta_scelta;
	int dim_griglia_scelta;
	stringa nome_partita;
	griglia griglia_sudoku;
	impostazioni impostazioni_gioco;
	partita partita_da_giocare;
	bool_t nome_impostato;
	bool_t nome_vuoto;
	bool_t nome_errato;

	nome_errato = FALSO;
	nome_impostato = FALSO;
	nome_vuoto = FALSO;
	uscito = FALSO;
	difficolta_scelta = DIFFICOLTA_STANDARD;
	dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	stringa_scrivere_dimensione(&nome_partita, 0);

	do {
		stampare_interfaccia_impostazioni();
		if (nome_impostato == FALSO && nome_vuoto == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_NOME_FILE_VUOTO);
		} else if (nome_impostato == FALSO && nome_errato == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_NOME_FILE_ERRATO);
		} else if (nome_impostato == FALSO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_NOME_FILE);
		}
		nome_errato = FALSO;
		nome_vuoto = FALSO;
		comando_utente = nascondere_input_utente();
		if(comando_utente == '1') {
			difficolta_scelta = selezionare_difficolta(difficolta_scelta);
		}
		if(comando_utente == '2') {
			dim_griglia_scelta = selezionare_dimensione_griglia(dim_griglia_scelta);
		}
		if(comando_utente == '3') {
			impostare_coordinate_cursore(56, 12);
			printf(": ");
			mostrare_cursore();
			prendere_input_stringa_limitato(&nome_partita, DIM_MAX_STRINGA - strlen(ESTENSIONE_FILE), 58, 12);
			if (controllare_caratteri_stringa(nome_partita, CARATTERI_NOME_FILE_NON_AMMESSI) == FALSO) {
				nome_impostato = FALSO;
				nome_errato = VERO;
			} else if (stringa_leggere_dimensione(nome_partita) <= 0) {
				nome_impostato = FALSO;
				nome_vuoto = VERO;
			} else {
				nome_impostato = VERO;
			}

		}
		if(comando_utente == '4' && nome_impostato == VERO) {
			impostare_parametri_di_gioco(&impostazioni_gioco, difficolta_scelta, dim_griglia_scelta);
			inizializzare_griglia(&griglia_sudoku, impostazioni_gioco);
			inizializzare_partita(impostazioni_gioco, griglia_sudoku, nome_partita, &partita_da_giocare);
			partite_salvate = giocare_partita(partita_da_giocare);
			uscito = VERO; //Se l'utente ha premuto ESC, deve uscire da questa funzione in modo da tornare al menu principale
		}
	} while(comando_utente != '5' && !uscito);
	return;
}

void menu_principale(stringa* partite_salvate) {
	char comando_utente;
	partita partita_caricata;
	bool_t caricato;
	do {
		stampare_interfaccia_menu_principale();
		comando_utente = nascondere_input_utente();
		if (comando_utente == '1') {
			iniziare_partita(partite_salvate);
		}
		if (comando_utente == '2') {
			caricato = caricare_partita(&partita_caricata);
			if (caricato == VERO) {
				partite_salvate = giocare_partita(partita_caricata);
			}
		}
	} while(comando_utente != '3');
	return;
}

void stampare_interfaccia_menu_principale() {
	int voci_menu_x;
	int inizio_voci_menu_y;
	voci_menu_x = 32;
	inizio_voci_menu_y = 12;
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| SUDOKU |", LARGHEZZA_FINESTRA, 1);
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+--------+", LARGHEZZA_FINESTRA, 2);
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y);
	printf("1. Inizia partita");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 1);
 	printf("2. Carica partita");
 	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 2);
	printf("3. Esci");
}
