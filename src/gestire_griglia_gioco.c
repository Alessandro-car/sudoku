#include "gestire_griglia_gioco.h"

/*	Funzione: n_numeri_di_griglia()
 * 	Descrizione: Questa funzione calcola, in base alla difficolta e alla dimenione della griglia scelta,
 * 				quante celle della griglia devono essere scoperte all'avvio del gioco
 * 	Parametri:
 * 		-impostazioni_gioco, impostazioni del gioco scelte dall'utente
 *	Dato di ritorno:
 *		-numeri_da_inserire_in_griglia, intero che indica quante numeri bisogna inserire nella griglia all'avvio della partita
 */

int n_numeri_di_griglia(impostazioni impostazioni_gioco) {
	int difficolta;				//Difficolta di gioco scelta dall'utente
	int dimensione_griglia;		//Dimensione della griglia scelta dall'utente
	int numeri_da_inserire_in_griglia;

	difficolta = impostazioni_leggere_difficolta(impostazioni_gioco);
	dimensione_griglia = impostazioni_leggere_dimensione_griglia(impostazioni_gioco);
	if (difficolta == 0){
		numeri_da_inserire_in_griglia = (dimensione_griglia * dimensione_griglia) * PERCENTUALE_DIFFICOLTA_FACILE;
	}
	if (difficolta == 1){
		numeri_da_inserire_in_griglia = (dimensione_griglia * dimensione_griglia) * PERCENTUALE_DIFFICOLTA_MEDIA;
}
	if (difficolta == 2){
		numeri_da_inserire_in_griglia = (dimensione_griglia * dimensione_griglia) * PERCENTUALE_DIFFICOLTA_DIFFICILE;
	}
	return numeri_da_inserire_in_griglia;
}

/*	Funzione: aggiornare_griglia()
 * 	Descrizione: Questa funzione inserisce un valore dato nella griglia nella posizione data
 * 	Parametri:
 * 		-griglia, griglia nella quale inserire il valore
 * 		-riga, riga della griglia nella quale inserire il valore
 * 		-coordinata_y, colonna della griglia nella quale inserire il valore
 *	Dato di ritorno:
 *		-griglia, la griglia aggiornata
 */
void aggiornare_griglia(griglia* griglia, int valore, int riga, int colonna){
	valore_griglia val;
	valore_griglia_scrivere_valore(&val, valore);
	valore_griglia_scrivere_modificabile(&val, VERO);
	griglia_scrivere_valore(griglia, riga - 1, colonna - 1, val);
	return;
}

/*	Funzione: azzerare_griglia()
 * 	Descrizione: Questa funzione imposta la griglia con tutti i valori a 0
 * 	Parametri:
 * 		-griglia_gioco, griglia di gioco
 *	Dato di ritorno:
 *		-griglia_gioco: la griglia con i valori impostati a 0
 */
void azzerare_griglia(griglia* griglia_gioco) {
	valore_griglia val; 	//Valore della griglia nella riga 'i' e colonna 'j'
	int i; 					//Indice della riga della griglia
	int j;					//Indice della colonna della griglia
	i = 0;
	while (i < griglia_leggere_dimensione(*griglia_gioco)) {
		j = 0;
		while (j < griglia_leggere_dimensione(*griglia_gioco)) {
			valore_griglia_scrivere_modificabile(&val, VERO);
			valore_griglia_scrivere_valore(&val, 0);
			griglia_scrivere_valore(griglia_gioco, i, j, val);
			j = j + 1;
		}
		i = i + 1;
	}
	return;
}

/*	Funzione: inizializzare_griglia()
 * 	Descrizione: Questa funzione inizializza la griglia impostandone la dimensione scelta dall'utente e i valori della griglia a 0
 * 	Parametri:
 * 		-griglia_gioco, griglia di gioco
 * 		-impostazioni_selezionate, impostazioni di gioco scelte dall'utente
 *	Dato di ritorno:
 *		-griglia_gioco, griglia inizializzata con dimensione e valori impostati a 0
 */
void inizializzare_griglia(griglia* griglia_gioco, impostazioni impostazioni_selezionate) {
	griglia_scrivere_dimensione(griglia_gioco, impostazioni_leggere_dimensione_griglia(impostazioni_selezionate));
	azzerare_griglia(griglia_gioco);
	riempire_griglia(griglia_gioco, impostazioni_selezionate);
	return;
}

/*	Funzione: riempire_griglia()
 * 	Descrizione: Questa funzione imposta dei valori casuali in delle coordinate casuali della griglia.
 * 				Il numero dei valori da impostare è dato dalla funzione n_numeri_di_griglia()
 * 	Parametri:
 * 		-griglia_gioco, griglia di gioco
 * 		-impostazioni_utente, impostazioni di gioco scelte dall'utente
 * 	Dato di ritorno:
 *		-griglia_gioco, griglia di gioco aggiornata con le celle riempite
 */
void riempire_griglia(griglia* griglia_gioco, impostazioni impostazioni_utente){
	int numeri_da_inserire;     //Rappresenta il numero di elementi che verrano inseriri in griglia
	int coordinata_x;           //Rappresenta una posizione casuale tra le righe
	int coordinata_y;           //Rappresenta una posizione casuale tra le colonne
	int valore;  				//Rappresenta il valore che verrà inserito nella griglia
	int i;						//Indice della riga della griglia
	valore_griglia val;

	i = 0;
	srand(time(NULL));          //Serve per la funzione rand, se non si mette, rand utilizza sempre la stessa sequenza di numeri.
	numeri_da_inserire = n_numeri_di_griglia(impostazioni_utente);

	while(i < numeri_da_inserire) {
		coordinata_x = (rand() % griglia_leggere_dimensione(*griglia_gioco));
		coordinata_y = (rand() % griglia_leggere_dimensione(*griglia_gioco));
		//Se la cella è vuota allora calcoliamo il valore casuale da inserire
		if(verificare_coordinate(*griglia_gioco, coordinata_x, coordinata_y) == VERO){
			valore = (rand() % griglia_leggere_dimensione(*griglia_gioco)) + 1;
			//Controlliamo se il valore può essere inserito nella griglia
			if(verificare_numero_da_inserire(*griglia_gioco, valore, coordinata_x, coordinata_y) == VERO){
				valore_griglia_scrivere_modificabile(&val, FALSO); //I valori generati non possono essere modificati dall'utente
				valore_griglia_scrivere_valore(&val, valore);
				griglia_scrivere_valore(griglia_gioco, coordinata_x, coordinata_y, val);
				i = i + 1;
			}
		}
	}
	return;
}

/*	Funzione: stampare_griglia()
 * 	Descrizione: Questa funzione stampa la griglia di gioco.
 * 	Le aree delle regioni e il contorno della griglia sono stampati con il colore grigio.
 * 	I numeri inseriti dall'utente in bianco e i numeri non modificabili in blu.
 * 	Gli indicatori di riga e colonna sono stampati in grigio.
 * 	Parametri:
 * 		-griglia_gioco, griglia di gioco da stampare
 */
void stampare_griglia(griglia griglia_gioco) {
	valore_griglia val; 			//Valore della griglia in una data coordinata
	char val_carattere;				//Valore della griglia in carattere
	int dim_griglia;				//Dimensione della griglia
	int dim_regione;				//Dimensione di una regione
	int n_regioni;					//Numero delle regioni
	int i;							//Indice delle righe della griglia
	int j;							//Indice delle colonne della griglia
	int rosso;						//Tonalità di rosso del colore RGB
	int verde;						//Tonalità di verde del colore RGB
	int blu;						//Tonalità di blu del colore RGB
	int inizio_griglia_x;			//Inizio della colonna dove stampare la griglia
	int inizio_griglia_y;			//Inizio della riga dove stampare la griglia

	rosso = 100;
	verde = 100;
	blu = 100;
	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	dim_regione = calcolare_radice_quadrata(dim_griglia);
	//Ci posizionamo al centro dello spazio riservato alla griglia
	inizio_griglia_x = (SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X - dim_griglia * 2) / 2 + 1;
	inizio_griglia_y = (SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_Y - (dim_griglia + dim_regione - 1)) / 2 + 1;
	i = 0;
	n_regioni = 0;
	//Stampiamo gli indicatori di riga e colonna della griglia per facilitare l'input all'utente
	while (i < dim_griglia) {
		j = 0;
		//Ci calcoliamo il numero delle regioni nella griglia
		if (calcolare_resto_intero(i, dim_regione) == 0 && i != 0) {
			n_regioni = n_regioni + 1;
		}
		while (j < dim_griglia) {
			impostare_coordinate_cursore(inizio_griglia_x + (j * 2), inizio_griglia_y);
			j = j + 1;
			stampare_carattere_colorato_rgb(rosso, verde, blu, convertire_numeri_in_lettere(j));
		}
		impostare_coordinate_cursore(inizio_griglia_x - 2, inizio_griglia_y + 1 + i + n_regioni);
		i = i + 1;
		stampare_carattere_colorato_rgb(rosso, verde, blu, convertire_numeri_in_lettere(i));
	}

	i = 0;
	//Stampiamo i contorni della griglia
	while (i < dim_griglia + dim_regione - 1) {
		j = 0;
		while (j <= dim_griglia * 2) {
			impostare_coordinate_cursore(inizio_griglia_x - 1 + j, inizio_griglia_y + 1 + i);
			if (calcolare_resto_intero(j, dim_regione * 2) == 0) {
				stampare_colorato_rgb(rosso, verde, blu, "|");
			}
			j = j + 2;
		}
		i = i + 1;
	}

	//Stampiamo i delimitatori di regione in modo da rendere più leggibile la griglia
	i = dim_regione;
	while(i < dim_griglia) {
		j = 0;
		while (j <= dim_griglia * 2) {
			impostare_coordinate_cursore(inizio_griglia_x - 1 + j, inizio_griglia_y + 1 + i);
			if (calcolare_resto_intero(j, dim_regione * 2) == 0) {
				stampare_colorato_rgb(rosso, verde, blu, "+");
			} else {
				stampare_colorato_rgb(rosso, verde, blu, "-");
			}
			j = j + 1;
		}
		i = i + dim_regione + 1;
	}

	i = 0;
	n_regioni = 0;
	//Stampiamo i numeri all'interno della griglia separandoli con uno spazio
	while (i < dim_griglia) {
	j = 0;
	if (calcolare_resto_intero(i, dim_regione) == 0 && i != 0) {
		n_regioni = n_regioni + 1;
	}
	while(j < dim_griglia) {
			impostare_coordinate_cursore(inizio_griglia_x + (j * 2), inizio_griglia_y + 1 + i + n_regioni);
			val = griglia_leggere_valore(griglia_gioco, i, j);
			val_carattere = convertire_numeri_in_lettere(valore_griglia_leggere_valore(val));
			if (val_carattere == '0') {
				printf(" ");
			} else {
				if (valore_griglia_leggere_modificabile(val) == FALSO) {
					stampare_carattere_colorato(COLORE_ANSI_CIANO, val_carattere);
				} else {
					printf("%c", val_carattere);
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}

	return;
}

