#ifndef GESTIRE_MENU_PRINCIPALE_H_
#define GESTIRE_MENU_PRINCIPALE_H_

#include "costanti.h"
#include "messaggi_errori.h"
#include "gestire_griglia_gioco.h"
#include "gestire_impostazioni.h"
#include "gestire_partita.h"
#include "gestire_salvataggi.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/impostazioni.h"
#include "tipi_di_dato/partita.h"
#include "tipi_di_dato/stringa.h"
#include "utilita.h"

void iniziare_partita(stringa* partite_salvate, bool_t prima_partita);
void menu_principale(stringa* partite_salvate, bool_t prima_partita);
void stampare_interfaccia_menu_principale();

#endif
