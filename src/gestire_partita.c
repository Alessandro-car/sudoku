#include "gestire_partita.h"


int validare_valore_input(int valore, int dim_griglia) {

int validato;
int dim_griglia_carattere;

validato = 1;
dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

if(dim_griglia >= 16 && (valore < 48 || (valore > 57 && valore < 65) || valore > dim_griglia_carattere )) {
	validato = 0;
} else {
	if(dim_griglia < 16 && (valore < 48 || valore >57))  {
		validato = 0;
	}
}
	return validato;
}

int verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna) {

	int corretto;
	int i;
	int j;
	int dimensione_griglia;
	int dimensione_regione;

	dimensione_griglia = griglia_leggere_dimensione(griglia);
	dimensione_regione = calcolare_radice_quadrata(dimensione_griglia);
	corretto = controllare_riga(griglia, riga, numero_da_inserire, dimensione_griglia);

	if(corretto == 1) {
		corretto = controllare_colonna(griglia, colonna, numero_da_inserire, dimensione_griglia);
	}
	if(corretto == 1) {
		riga = riga - calcolare_resto_intero(riga, dimensione_regione);
		colonna =  colonna - calcolare_resto_intero(colonna, dimensione_regione);
		corretto = controllare_regione(griglia, riga, colonna, numero_da_inserire, dimensione_regione);
	}
	return corretto;
}


