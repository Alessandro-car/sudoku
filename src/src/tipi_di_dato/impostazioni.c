#include "impostazioni.h"

int impostazioni_leggere_difficolta(impostazioni impostazioni_partita) {
	int livello_difficolta;
	livello_difficolta = impostazioni_partita.difficolta;
	return livello_difficolta;
}

int impostazioni_leggere_dimensione_griglia(impostazioni impostazioni_partita) {
	int dimensione_griglia;
	dimensione_griglia = impostazioni_partita.dimensione_griglia;
	return dimensione_griglia;
}


void impostazioni_scrivere_difficolta(impostazioni* impostazioni_partita, int nuova_difficolta) {
	impostazioni_partita->difficolta = nuova_difficolta;
	return;
}

void impostazioni_scrivere_dimensione_griglia(impostazioni* impostazioni_partita, int nuova_dimensione) {
	impostazioni_partita->dimensione_griglia = nuova_dimensione;
	return;
}

