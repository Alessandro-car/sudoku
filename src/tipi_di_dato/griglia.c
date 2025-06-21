#include "griglia.h"

int griglia_leggere_dimensione(griglia griglia_partita) {
	int dimensione_griglia;
	dimensione_griglia = griglia_partita.dimensione_griglia;
	return dimensione_griglia;
}

void griglia_scrivere_dimensione(griglia* griglia_partita, int nuova_dimensione) {
	griglia_partita->dimensione_griglia = nuova_dimensione;
	return;
}

valore_griglia griglia_leggere_valore(griglia griglia_partita, int riga, int colonna) {
	valore_griglia valore_letto;
	valore_letto = griglia_partita.valori[riga][colonna];
	return valore_letto;
}

void griglia_scrivere_valore(griglia* griglia_partita, int riga, int colonna, valore_griglia val) {
	griglia_partita->valori[riga][colonna] = val;
	return;
}
