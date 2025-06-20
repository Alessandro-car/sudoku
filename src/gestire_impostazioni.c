#include "gestire_impostazioni.h"

int selezionare_difficolta(int difficolta_scelta) {
	menu_scelta_difficolta();
	char comando_utente;
	comando_utente = nascondere_input_utente();
	difficolta_scelta = DIFFICOLTA_STANDARD;
	if (comando_utente == '1'){
		difficolta_scelta = DIFFICOLTA_STANDARD;
	}
	if (comando_utente == '2'){
		difficolta_scelta = DIFFICOLTA_MEDIA;
	}
	if (comando_utente == '3'){
		difficolta_scelta = DIFFICOLTA_DIFFICILE;
	}
	return difficolta_scelta;
}

void menu_scelta_dimensione_griglia() {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	impostare_coordinate_cursore(32, 1);
	printf("| DIMENSIONE |");
	impostare_coordinate_cursore(32, 2);
	printf("+------------+");
	impostare_coordinate_cursore(31, 11);
	printf("1. Piccola:  4 x 4");
	impostare_coordinate_cursore(31, 12);
	printf("2. Standard: 9 x 9");
	impostare_coordinate_cursore(31, 13);
	printf("3. Grande:   16 x 16");
	impostare_coordinate_cursore(31, 14);
	printf("4. Torna indietro");
	return;
}

int selezionare_dimensione_griglia() {
	menu_scelta_dimensione_griglia();
	char comando_utente;
	comando_utente = nascondere_input_utente();
	int dim_griglia_scelta;
	dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	if (comando_utente == '1') {
		dim_griglia_scelta = DIM_GRIGLIA_PICCOLA;
	}
	if (comando_utente == '2') {
		dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	}
	if (comando_utente == '3') {
		dim_griglia_scelta = DIM_GRIGLIA_GRANDE;
	}
	return dim_griglia_scelta;
}

void impostare_parametri_di_gioco(impostazioni* impostazioni_gioco, int difficolta_scelta, int dim_griglia_scelta) {
	impostazioni_scrivere_difficolta(impostazioni_gioco, difficolta_scelta);
	impostazioni_scrivere_dimensione_griglia(impostazioni_gioco,dim_griglia_scelta);
}

//Funzione che stampa a video il menù di scelta della difficoltà.
void menu_scelta_difficolta() {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	impostare_coordinate_cursore(33, 1);
	printf("| DIFFICOLTA |");
	impostare_coordinate_cursore(33, 2);
	printf("+------------+");
	impostare_coordinate_cursore(33, 11);
	printf("1. Facile");
	impostare_coordinate_cursore(33, 12);
	printf("2. Medio");
	impostare_coordinate_cursore(33, 13);
	printf("3. Difficile");
	impostare_coordinate_cursore(33, 14);
	printf("4. Indietro");

	return;
}

//Funzione che si occupa di inizializzare la struttura partita.
void inizializzare_partita(impostazioni impostazioni_utente, griglia griglia, stringa nome_partita, partita* partita) {
	partita_scrivere_impostazioni(partita, impostazioni_utente);
	partita_scrivere_griglia(partita, griglia);
	partita_scrivere_nome(partita, nome_partita);
	return;
}
