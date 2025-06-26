#include "gestire_griglia_gioco.h"

int n_numeri_di_griglia(impostazioni impostazioni_gioco) {
	int difficolta;
	int dimensione_griglia;
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

void aggiornare_griglia(griglia* griglia, int valore, int riga, int colonna){
	valore_griglia val;
	valore_griglia_scrivere_valore(&val, valore);
	valore_griglia_scrivere_modificabile(&val, VERO);
	griglia_scrivere_valore(griglia, riga - 1, colonna - 1, val);
	return;
}

void azzerare_griglia(griglia* griglia_gioco) {
	valore_griglia val;
	int i;
	int j;
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

void inizializzare_griglia(griglia* griglia_gioco, impostazioni impostazioni_selezionate) {
	griglia_scrivere_dimensione(griglia_gioco, impostazioni_leggere_dimensione_griglia(impostazioni_selezionate));
	azzerare_griglia(griglia_gioco);
	riempire_griglia(griglia_gioco, impostazioni_selezionate);
	return;
}

void riempire_griglia(griglia* griglia_gioco, impostazioni impostazioni_utente){
	int numeri_da_inserire;     //Rappresenta il numero di elementi che verrano inseriri in griglia
	int coordinata_x;           //Rappresenta una posizione casuale tra le righe
	int coordinata_y;           //Rappresenta una posizione casuale tra le colonne
	int valore;  				//Rappresenta il valore che verrà inserito nella griglia
	int i;
	valore_griglia val;

	i = 0;
	srand(time(NULL));          //Serve per la funzione rand, se non si mette, rand utilizza sempre la stessa sequenza di numeri.
	numeri_da_inserire = n_numeri_di_griglia(impostazioni_utente);

	while(i < numeri_da_inserire) {
		coordinata_x = (rand() % griglia_leggere_dimensione(*griglia_gioco));
		coordinata_y = (rand() % griglia_leggere_dimensione(*griglia_gioco));
		if(verificare_coordinate_e_valore(*griglia_gioco, coordinata_x, coordinata_y) == VERO){
			valore = (rand() % griglia_leggere_dimensione(*griglia_gioco)) + 1;
			if(verificare_numero_da_inserire(*griglia_gioco, valore, coordinata_x, coordinata_y) == VERO){
					valore_griglia_scrivere_modificabile(&val, FALSO);
					valore_griglia_scrivere_valore(&val, valore);
					griglia_scrivere_valore(griglia_gioco, coordinata_x, coordinata_y, val);
					i = i + 1;
			}
		}
	}
	return;
}

void stampare_griglia(griglia griglia_gioco) {
	valore_griglia val;
	char val_carattere;
	int dim_griglia;
	int dim_regione;
	int n_regioni;
	int i;
	int j;
	int rosso;
	int verde;
	int blu;
	int start_pos_x;
	int start_pos_y;

	rosso = 100;
	verde = 100;
	blu = 100;
	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	dim_regione = calcolare_radice_quadrata(dim_griglia);
	start_pos_x = (SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X - dim_griglia * 2) / 2 + 1;
	start_pos_y = (SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_Y - (dim_griglia + dim_regione - 1)) / 2 + 1;
	i = 0;
	n_regioni = 0;
	while (i < dim_griglia) {
		j = 0;
		if (calcolare_resto_intero(i, dim_regione) == 0 && i != 0) {
			n_regioni = n_regioni + 1;
		}
		while (j < dim_griglia) {
			impostare_coordinate_cursore(start_pos_x + (j * 2), start_pos_y);
			j = j + 1;
			stampare_carattere_colorato_rgb(rosso, verde, blu, convertire_numeri_in_lettere(j));
		}
		impostare_coordinate_cursore(start_pos_x - 2, start_pos_y + 1 + i + n_regioni);
		i = i + 1;
		stampare_carattere_colorato_rgb(rosso, verde, blu, convertire_numeri_in_lettere(i));
	}

	i = 0;
	while (i < dim_griglia + dim_regione - 1) {
		j = 0;
		while (j <= dim_griglia * 2) {
			impostare_coordinate_cursore(start_pos_x - 1 + j, start_pos_y + 1 + i);
			if (calcolare_resto_intero(j, dim_regione * 2) == 0) {
				stampare_colorato_rgb(rosso, verde, blu, "|");
			}
			j = j + 2;
		}
		i = i + 1;
	}

	i = dim_regione;
	while(i < dim_griglia) {
		j = 0;
		while (j <= dim_griglia * 2) {
			impostare_coordinate_cursore(start_pos_x - 1 + j, start_pos_y + 1 + i);
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
	while (i < dim_griglia) {
	j = 0;
	if (calcolare_resto_intero(i, dim_regione) == 0 && i != 0) {
		n_regioni = n_regioni + 1;
	}
	while(j < dim_griglia) {
			impostare_coordinate_cursore(start_pos_x + (j * 2), start_pos_y + 1 + i + n_regioni);
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

