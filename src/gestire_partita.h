#ifndef GESTIRE_PARTITA_H_
#define GESTIRE_PARTITA_H_

#include "tipi_di_dato/griglia.h"
#include "utils.h"

int validare_valore_input(int valore, int dim_griglia);
int validare_valore_input(int valore, int dim_griglia);
int verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna);
bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione);
bool_t validare_riga_input(int riga, int dim_griglia);

#endif
