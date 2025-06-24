#include "gestire_menu_principale.h"

void iniziare_partita() {
	bool_t uscito;
	char comando_utente;
	int difficolta_scelta;
	int dim_griglia_scelta;
	stringa nome_partita;
	griglia griglia_sudoku;
	impostazioni impostazioni_gioco;
	partita partita_da_giocare;
	bool_t nome_impostato;

	nome_impostato = FALSO;
	uscito = FALSO;
	difficolta_scelta = DIFFICOLTA_STANDARD;
	dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	stringa_scrivere_dimensione(&nome_partita, 0);

	do {
		stampare_interfaccia_impostazioni();
		if (nome_impostato == FALSO) {
			stampare_banner_errore(1, 24, 80, ERRORE_NOME_FILE);
		}
		comando_utente = nascondere_input_utente();
		if(comando_utente == '1') {
			difficolta_scelta = selezionare_difficolta(difficolta_scelta);
		}
		if(comando_utente == '2') {
			dim_griglia_scelta = selezionare_dimensione_griglia();
		}
		if(comando_utente == '3') {
			impostare_coordinate_cursore(56, 12);
			printf(":");
			prendere_input_stringa_limitato(&nome_partita, DIM_MAX_STRINGA, 58, 12);
			nome_impostato = VERO;
		}
		if(comando_utente == '4' && nome_impostato == VERO) {
			impostare_parametri_di_gioco(&impostazioni_gioco, difficolta_scelta, dim_griglia_scelta);
			inizializzare_griglia(&griglia_sudoku, impostazioni_gioco);
			inizializzare_partita(impostazioni_gioco, griglia_sudoku, nome_partita, &partita_da_giocare);
			giocare_partita(partita_da_giocare);
			uscito = VERO; //Se l'utente ha premuto ESC, deve uscire da questa funzione in modo da tornare al menu principale
		}
	} while(comando_utente != '5' && !uscito);
	return;
}

void menu_principale() {
	int comando_utente;
	partita partita_caricata;
	bool_t caricato;
	do {
		stampare_interfaccia_menu_principale();
		comando_utente = nascondere_input_utente();
		if (comando_utente == '1') {
			iniziare_partita();
		}
		if (comando_utente == '2') {
			caricato = caricare_partita(&partita_caricata);
			if (caricato == VERO) {
				giocare_partita(partita_caricata);
			}
		}
	} while(comando_utente != '3');
	return;
}

void stampare_interfaccia_menu_principale() {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	impostare_coordinate_cursore(34, 1);
	printf("| SUDOKU |");
	impostare_coordinate_cursore(34, 2);
	printf("+--------+");
	impostare_coordinate_cursore(31, 12);
	printf("1. Inizia partita");
	impostare_coordinate_cursore(31, 13);
 	printf("2. Carica partita");
 	impostare_coordinate_cursore(31, 14);
	printf("3. Esci");
}
