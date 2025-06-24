#include "stringa.h"

#include <stdlib.h>

char* stringa_leggere_array(stringa str) {
	char* stringa_letta;
	int dim_stringa;
	int i;

	dim_stringa = stringa_leggere_dimensione(str);
	stringa_letta = calloc(dim_stringa + 1, sizeof(char));
	i = 0;
	while(i < dim_stringa) {
		*(stringa_letta + i) = stringa_leggere_carattere(str, i);
		i = i + 1;
	}
	stringa_letta[i] = '\0';
	return stringa_letta;
}

char stringa_leggere_carattere(stringa str, int pos) {
	char carattere_letto;
	carattere_letto = str.caratteri[pos];
	return carattere_letto;
}


int stringa_leggere_dimensione(stringa str) {
	int dimensione;
	dimensione = str.dimensione_stringa;
	return dimensione;
}

void stringa_scrivere_array(stringa* str, char* caratteri, int dim_stringa) {
	int i;
	stringa_scrivere_dimensione(str, dim_stringa);
	i = 0;
	while (i < dim_stringa) {
		stringa_scrivere_carattere(str, i, caratteri[i]);
		i = i + 1;
	}
	stringa_scrivere_carattere(str, i, '\0');
	return;
}

void stringa_scrivere_carattere(stringa* str, int pos, char carattere) {
	str->caratteri[pos] = carattere;
	return;
}

void stringa_scrivere_dimensione(stringa* str, int nuova_dimensione) {
	str->dimensione_stringa = nuova_dimensione;
	return;
}
