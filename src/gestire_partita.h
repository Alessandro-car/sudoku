#ifndef GESTIRE_PARTITA_H_
#define GESTIRE_PARTITA_H_

#include "costanti.h"
#include "messaggi_errori.h"
#include "gestire_salvataggi.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/partita.h"
#include "tipi_di_dato/stringa.h"
#include "utilita.h"

bool_t controllare_colonna(griglia griglia, int colonna, int numeri_da_inserire, int dimensione_griglia);
bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione);
bool_t controllare_riga(griglia sudoku, int riga, int numero_da_inserire, int dimensione_sudoku);
bool_t validare_colonna_input(int colonna, int dim_griglia);
bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco);
bool_t validare_riga_input(int riga, int dim_griglia);
bool_t validare_valore_input(char valore, int dim_griglia);
bool_t verificare_coordinate_e_valore(griglia griglia_gioco, int coordinata_x, int coordinata_y, int valore);
bool_t verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna);
void aggiornare_griglia(griglia* griglia, int valore, int riga, int colonna);
void giocare_partita(partita partita_corrente);
void stampare_informazioni_utente(partita partita_corrente);
void stampare_interfaccia_impostazioni(void);
void stampare_schermata_di_gioco(partita partita_corrente);
void stampare_griglia(griglia griglia_gioco);

#endif
