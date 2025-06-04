#ifndef GRIGLIA_H_
#define GRIGLIA_H_

#include "costanti.h"

typedef struct {
	int dimensione_griglia;
	int valori_griglia[DIM_MAX_GRIGLIA][DIM_MAX_GRIGLIA];
} griglia;

int griglia_leggere_dimensione(griglia griglia_partita);
void griglia_scrivere_dimensione(griglia* griglia_partita, int nuova_dimensione);
int griglia_leggere_valore(griglia griglia_partita, int riga, int colonna);
void griglia_scrivere_valore(griglia* griglia_partita, int riga, int colonna, int valore);

#endif
