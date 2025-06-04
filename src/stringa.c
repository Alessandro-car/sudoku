#include "stringa.h"

int stringa_leggere_dimensione(stringa str) {
	int dimensione;
	dimensione = str.dimensione_stringa;
	return dimensione;
}

void stringa_scrivere_dimensione(stringa* str, int nuova_dimensione) {
	str->dimensione_stringa = nuova_dimensione;
	return;
}

char stringa_leggere_carattere(stringa str, int pos) {
	char carattere_letto;
	carattere_letto = str.caratteri[pos];
	return carattere_letto;
}

void stringa_scrivere_carattere(stringa* str, int pos, char carattere) {
	str->caratteri[pos] = carattere;
	return;
}

