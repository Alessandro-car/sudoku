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

int griglia_leggere_valore(griglia griglia_partita, int riga, int colonna) {
	int valore_letto;
	valore_letto = griglia_partita.valori_griglia[riga][colonna];
	return valore_letto;
}

void griglia_scrivere_valore(griglia* griglia_partita, int riga, int colonna, int valore) {
	griglia_partita->valori_griglia[riga][colonna] = valore;
	return;
}
