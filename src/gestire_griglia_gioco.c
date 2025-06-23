#include "gestire_griglia_gioco.h"

//Funzione per determinare quanti numeri inserire inizialmente nella griglia
int n_numeri_di_griglia(impostazioni impostazioni_gioco) {
	int difficolta;				//Difficoltà scelta in precedenza dall'utente
	int dimensione_griglia;			//Dimensione della griglia del sudoku
	int numeri_da_inserire_in_griglia;		//Numeri da inserire ad inizio partita in base alla difficoltà e alla dimensione della griglia

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

//TODO: Modificare lo pseudocodice di questa funzione
//Funzione che si occupa di riempire la griglia iniziale seguendo le impostazioni utente
void riempire_griglia(griglia* griglia_gioco, impostazioni impostazioni_utente){
	int numeri_da_inserire;     //Rappresenta il numero di elementi che verrano inseriri in griglia
	int coordinata_x;           //Rappresenta una posizione casuale tra le righe
	int coordinata_y;           //Rappresenta una posizione casuale tra le colonne
	int valore;                 //Rappresenta il valore che verrà inserito nella griglia
	valore_griglia val;
	int i;

	i = 0;
	srand(time(NULL));          //Serve per la funzione rand, se non si mette, rand utilizza sempre la stessa sequenza di numeri.
	numeri_da_inserire = n_numeri_di_griglia(impostazioni_utente);

	while(i < numeri_da_inserire){
		coordinata_x = (rand() % griglia_leggere_dimensione(*griglia_gioco));
		coordinata_y = (rand() % griglia_leggere_dimensione(*griglia_gioco));
		if(verificare_coordinate_e_valore(*griglia_gioco, coordinata_x, coordinata_y, valore) == VERO){
				valore = (rand() % griglia_leggere_dimensione(*griglia_gioco)) + 1;
				if(verificare_numero_da_inserire(*griglia_gioco, valore, coordinata_x, coordinata_y) == VERO){
						valore_griglia_scrivere_modificabile(&val, FALSO);
						if(valore > 9){
							valore = convertire_numeri_in_lettere(valore);
						}
						valore_griglia_scrivere_valore(&val, valore);
						griglia_scrivere_valore(griglia_gioco, coordinata_x, coordinata_y, val);
						i = i + 1;
				}
		}
	}
	return;
}

//TODO: Creare la funzione in pseudo
void azzerare_griglia(griglia *griglia_gioco) {
	valore_griglia val;
	int i;
	int j;
	i = 0;
	valore_griglia_scrivere_modificabile(&val, VERO);
	while (i < griglia_leggere_dimensione(*griglia_gioco)) {
		j = 0;
		while (j < griglia_leggere_dimensione(*griglia_gioco)) {
			valore_griglia_scrivere_valore(&val, 0);
			griglia_scrivere_valore(griglia_gioco, i, j, val);
			j = j + 1;
		}
		i = i + 1;
	}
	return;
}
//TODO: Eliminare questa funzione e rinominare riempire_griglia come inizializzare_griglia
// Funzione che inizializza la griglia del Sudoku basandosi sulle impostazioni selezionate dall'utente
void inizializzare_griglia(griglia* griglia_gioco, impostazioni impostazioni_selezionate) {
	griglia_scrivere_dimensione(griglia_gioco, impostazioni_leggere_dimensione_griglia(impostazioni_selezionate));
	azzerare_griglia(griglia_gioco);
	riempire_griglia(griglia_gioco, impostazioni_selezionate);
	return;
}


