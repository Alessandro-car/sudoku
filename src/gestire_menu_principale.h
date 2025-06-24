#ifndef GESTIRE_MENU_PRINCIPALE_H_
#define GESTIRE_MENU_PRINCIPALE_H_

#include <stdio.h>
#include <stdlib.h>
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/impostazioni.h"
#include "tipi_di_dato/stringa.h"
#include "tipi_di_dato/partita.h"
#include "gestire_impostazioni.h"
#include "gestire_partita.h"
#include "gestire_griglia_gioco.h"
#include "gestire_salvataggi.h"
#include "utils.h"
#include "costanti.h"
#include "gestire_errori.h"

void stampare_interfaccia_menu_principale();
stringa* menu_principale();
stringa* iniziare_partita();

#endif
