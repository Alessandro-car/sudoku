#ifndef GESTIRE_GRIGLIA_GIOCO_H_
#define GESTIRE_GRIGLIA_GIOCO_H_

#include <time.h>

#include "costanti.h"
#include "gestire_controlli.h"
#include "gestire_griglia_gioco.h"
#include "gestire_partita.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/impostazioni.h"
#include "utilita.h"

int n_numeri_di_griglia(impostazioni impostazioni_gioco);
void aggiornare_griglia(griglia* griglia, int valore, int riga, int colonna);
void azzerare_griglia(griglia* griglia_gioco);
void inizializzare_griglia(griglia* griglia_gioco, impostazioni impostazioni_selezionate);
void riempire_griglia(griglia* griglia_gioco, impostazioni impostazioni_utente);
void stampare_griglia(griglia griglia_gioco);

#endif
