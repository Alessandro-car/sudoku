#ifndef GESTIRE_PARTITA_H_
#define GESTIRE_PARTITA_H_

#include <stdio.h>
#include "tipi_di_dato/gestire_partita.h"
#include "tipi_di_dato/griglia.h"
#include "utils.h"

griglia aggiornare_griglia (griglia griglia, int valore, int riga, int colonna);
bool_t validare_colonna_input(int colonna, int dim_griglia);
bool_t controllare_colonna(griglia griglia, int colonna, int numeri_da_inserire, int dimensione_griglia);
bool_t validare_valore_input(int valore, int dim_griglia);
bool_t verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna);
bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione);
bool_t validare_riga_input(int riga, int dim_griglia);
void salvare_partita(FILE* file_salvataggio, partita partita_da_salvare);
bool_t controllare_riga(griglia sudoku, int riga, int numero_da_inserire, int dimensione_sudoku);
stringa* giocare_partita(partita partita_corrente);
void stampare_interfaccia_impostazioni(void);
bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco);
void stampare_schermata_di_gioco(griglia griglia_gioco);
void stampa_griglia(griglia griglia_gioco);
void stampare_informazioni_utente();

#endif
