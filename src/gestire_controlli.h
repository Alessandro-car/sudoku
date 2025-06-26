#ifndef GESTIRE_CONTROLLI_H_
#define GESTIRE_CONTROLLI_H_

#include "costanti.h"
#include "tipi_di_dato/griglia.h"
#include "utilita.h"

bool_t controllare_colonna(griglia griglia, int colonna, int numeri_da_inserire);
bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione);
bool_t controllare_riga(griglia griglia, int riga, int numero_da_inserire);
bool_t validare_colonna_input(int colonna, int dim_griglia);
bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco);
bool_t validare_riga_input(int riga, int dim_griglia);
bool_t validare_valore_input(char valore, int dim_griglia);
bool_t verificare_coordinate(griglia griglia_gioco, int coordinata_x, int coordinata_y);
bool_t verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna);

#endif
