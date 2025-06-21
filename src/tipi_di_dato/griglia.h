#ifndef GRIGLIA_H_
#define GRIGLIA_H_


#include "../costanti.h"
#include "valore_griglia.h"

typedef struct {
	int dimensione_griglia;
	valore_griglia valori[DIM_GRIGLIA_GRANDE][DIM_GRIGLIA_GRANDE];
} griglia;


int griglia_leggere_dimensione(griglia griglia_partita);
void griglia_scrivere_dimensione(griglia* griglia_partita, int nuova_dimensione);
valore_griglia griglia_leggere_valore(griglia griglia_partita, int riga, int colonna);
void griglia_scrivere_valore(griglia* griglia_partita, int riga, int colonna, valore_griglia val);

#endif
