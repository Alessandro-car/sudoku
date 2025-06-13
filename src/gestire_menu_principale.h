#ifndef GESTIRE_MENU_PRINCIPALE_H_
#define GESTIRE_MENU_PRINCIPALE_H_

#include "tipi_di_dato/impostazioni.h"
#include "tipi_di_dato/stringa.h"
#include "tipi_di_dato/partita.h"

void stampare_interfaccia_menu_principale();
stringa* menu_principale();
stringa* iniziare_partita();
partita caricare_partita(stringa* partite_salvate);

#endif
