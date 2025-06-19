#ifndef GESTIRE_IMPOSTAZIONI_H_
#define GESTIRE_IMPOSTAZIONI_H_

#include <stdio.h>
#include "tipi_di_dato/impostazioni.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/stringa.h"
#include "tipi_di_dato/partita.h"
#include "costanti.h"
#include "utils.h"

void menu_scelta_dimensione_griglia();
int selezionare_dimensione_griglia();
int selezionare_difficolta(int difficolta_scelta);
void impostare_parametri_di_gioco(impostazioni* impostazioni_gioco, int difficolta_scelta, int dim_griglia_scelta);
void menu_scelta_difficolta();
void inizializzare_partita(impostazioni impostazioni_utente, griglia griglia, stringa nome_partita, partita *partita);

#endif
