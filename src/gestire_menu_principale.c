#include "gestire_menu_principale.h"

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


stringa* menu_principale() {
	int comando_utente;
	stringa* nome_partite_salvate;
	nome_partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));
	do {
		stampare_interfaccia_menu_principale();
		comando_utente = nascondere_input_utente();
		if (comando_utente == '1') {
			nome_partite_salvate = iniziare_partita();
		}
		if (comando_utente == '2') {
			partita partita_caricata;
			//TODO: gestire errore se non ci sono file salvati
			partita_caricata = caricare_partita(nome_partite_salvate);
			nome_partite_salvate = giocare_partita(partita_caricata);
		}
	} while(comando_utente != '3');
	return nome_partite_salvate;
}

stringa* iniziare_partita() {
	bool_t uscito;
	char comando_utente;
	int difficolta_scelta;
	int dim_griglia_scelta;
	stringa nome_partita;
	griglia griglia_sudoku;
	impostazioni impostazioni_gioco;
	partita partita_da_giocare;
	stringa* nome_partite_salvate;

	uscito = FALSO;
	difficolta_scelta = DIFFICOLTA_STANDARD;
	dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	nome_partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));


	do {
		stampare_interfaccia_impostazioni();
		comando_utente = nascondere_input_utente();
		if(comando_utente == '1') {
			difficolta_scelta = selezionare_difficolta(difficolta_scelta);
		}
		if(comando_utente == '2') {
			dim_griglia_scelta = selezionare_dimensione_griglia();
		}
		if(comando_utente == '3') {
			impostare_coordinate_cursore(56, 12);
			mostrare_cursore();
			printf(": ");
			prendere_input_stringa_limitato(&nome_partita, DIM_MAX_STRINGA, 58, 12);
		}
		if(comando_utente == '4') {
			impostare_parametri_di_gioco(&impostazioni_gioco, difficolta_scelta, dim_griglia_scelta);
			inizializzare_griglia(&griglia_sudoku, impostazioni_gioco);
			inizializzare_partita(impostazioni_gioco, griglia_sudoku, nome_partita, &partita_da_giocare);
			nome_partite_salvate = giocare_partita(partita_da_giocare);
			uscito = VERO; //Se l'utente ha premuto ESC, deve uscire da questa funzione in modo da tornare al menu principale
		}
	} while(comando_utente != '5' && !uscito);
	return nome_partite_salvate;
}


partita caricare_partita(stringa* partite_salvate) {
	stringa nome_file_scelto;
	int comando_utente;
	partita partita_caricata;

	//printf(interfaccia_caricare_partita);
	comando_utente = nascondere_input_utente();
	//file_scelto = partite_salvate[comando_utente];
	//TODO: Controllo se il numero di partite salvate e' > 0

	nome_file_scelto = partite_salvate[comando_utente];
	partita_caricata = caricare_partita_da_file(nome_file_scelto);
	return partita_caricata;
}

