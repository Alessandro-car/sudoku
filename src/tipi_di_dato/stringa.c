#include "stringa.h"

#include <stdlib.h>

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

char* stringa_leggere_array(stringa str) {
	char* stringa_letta;
	int dim_stringa = stringa_leggere_dimensione(str);
	stringa_letta = malloc(dim_stringa * sizeof(char));
	return stringa_letta;
}
