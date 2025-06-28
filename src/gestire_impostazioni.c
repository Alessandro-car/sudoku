#include "gestire_impostazioni.h"

/*	Funzione: selezionare_difficolta()
 * 	Descrizione: Questa funzione si occupa di far scegliere all'utente la difficolà di gioco
 * 	Parametri:
 * 		-difficolta_scelta, la difficolta di gioco che dovrà scegliere l'utente, il valore standard è 1
 *	Dato di ritorno:
 *		-difficolta_scelta, difficoltà scelta dall'utente
 */
int selezionare_difficolta(int difficolta_scelta) {
	char comando_utente;
	do {
		menu_scelta_difficolta();
		comando_utente = nascondere_input_utente();
		if (comando_utente == '1'){
			difficolta_scelta = DIFFICOLTA_STANDARD;
		}
		if (comando_utente == '2'){
			difficolta_scelta = DIFFICOLTA_MEDIA;
		}
		if (comando_utente == '3'){
			difficolta_scelta = DIFFICOLTA_DIFFICILE;
		}
	} while (comando_utente < '1' || comando_utente > '4');
	return difficolta_scelta;
}

/*	Funzione: selezionare_dimensione_griglia()
 * 	Descrizione: Questa funzione si occupa di far scegliere all'utente la dimensione della griglia di gioco
 * 	Parametri:
 * 		-dim_griglia_scelta, dimensione della griglia che l'utente dovrà scegliere, la standard è 9
 *	Dato di ritorno:
 *		-dim_griglia_scelta, dimensione della griglia scelta dall'utente
 */
int selezionare_dimensione_griglia(int dim_griglia_scelta) {
	char comando_utente;

	do {
		menu_scelta_dimensione_griglia();
		comando_utente = nascondere_input_utente();
		if (comando_utente == '1') {
			dim_griglia_scelta = DIM_GRIGLIA_PICCOLA;
		}
		if (comando_utente == '2') {
			dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
		}
		if (comando_utente == '3') {
			dim_griglia_scelta = DIM_GRIGLIA_GRANDE;
		}
	} while (comando_utente < '1' || comando_utente > '4');
	return dim_griglia_scelta;
}

/*	Funzione: n_numeri_di_griglia()
 * 	Descrizione: Questa funzione si occupa di impostare le impostazioni scelte dall'utente
 * 	Parametri:
 * 		-impostazioni_gioco, impostazioni di gioco da impostare
 * 		-difficolta_scelta, difficoltà di gicoo scelta dall'utente
 * 		-dim_griglia_scelta, dimensione della griglia scelta dall'utente
 *	Dato di ritorno:
 *		-impostazioni_gioco, impostazioni di gioco con la difficoltà e la dimensione impostate
 */
void impostare_parametri_di_gioco(impostazioni* impostazioni_gioco, int difficolta_scelta, int dim_griglia_scelta) {
	impostazioni_scrivere_difficolta(impostazioni_gioco, difficolta_scelta);
	impostazioni_scrivere_dimensione_griglia(impostazioni_gioco,dim_griglia_scelta);
	return;
}

/*	Funzione: inizializzare_partita()
 * 	Descrizione: Questa funzione inizializza la partita impostandone:
 * 					-Le impostazioni scelte dall'utente;
 * 					-Il nome della partita scelto dall'utente;
 * 					-La griglia di gioco generata
 * 	Parametri:
 * 		-impostazioni_utente, impostazioni di gioco scelte dall'utente
 * 		-griglia, griglia di gioco
 * 		-nome_partita, nome della partita scelto dall'utente
 * 		-partita, partita da inizializzare
 *	Dato di ritorno:
 *		-partita, la partita inizializzata con i dati elencati precedentemente
 */
void inizializzare_partita(impostazioni impostazioni_utente, griglia griglia, stringa nome_partita, partita* partita) {
	partita_scrivere_impostazioni(partita, impostazioni_utente);
	partita_scrivere_griglia(partita, griglia);
	partita_scrivere_nome(partita, nome_partita);
	return;
}

void menu_scelta_difficolta() {
	int voci_menu_x;
	int inizio_voci_menu_y;
	voci_menu_x = 33;
	inizio_voci_menu_y = 11;
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| DIFFICOLTA |", LARGHEZZA_FINESTRA, 1);
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+------------+",  LARGHEZZA_FINESTRA, 2);
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y);
	printf("1. Facile");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 1);
	printf("2. Medio");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 2);
	printf("3. Difficile");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 3);
	printf("4. Indietro");
	return;
}

void menu_scelta_dimensione_griglia() {
	int voci_menu_x;
	int inizio_voci_menu_y;
	voci_menu_x = 31;
	inizio_voci_menu_y = 11;
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| DIMENSIONE |", LARGHEZZA_FINESTRA, 1);
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+------------+",  LARGHEZZA_FINESTRA, 2);
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y);
	printf("1. Piccola:  4 x 4");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 1);
	printf("2. Standard: 9 x 9");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 2);
	printf("3. Grande:   16 x 16");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 3);
	printf("4. Torna indietro");
	return;
}

void stampare_interfaccia_impostazioni(void) {
	int inizio_voci_menu_y;
	int voci_menu_x;
	inizio_voci_menu_y = 10;
	voci_menu_x = 31;
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| IMPOSTAZIONI |", LARGHEZZA_FINESTRA, 1);
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+--------------+", LARGHEZZA_FINESTRA, 2);
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y);
	printf("1. Scegli difficolta'");
 	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 1);
 	printf("2. Scegli dimensione");
 	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 2);
 	printf("3. Inserisci nome partita");
 	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 3);
 	printf("4. Prosegui");
 	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 4);
 	printf("5. Torna indietro");
	return;
}

