#ifndef STRINGA_H_
#define STRINGA_H_

#include "costanti.h"

typedef struct {
	int dimensione_stringa;
	char caratteri[DIM_MAX_STRINGA];
} stringa;

int stringa_leggere_dimensione(stringa str);
void stringa_scrivere_dimensione(stringa* str, int nuova_dimensione);
char stringa_leggere_carattere(stringa str, int pos);
void stringa_scrivere_carattere(stringa* str, int pos, char carattere);

#endif
