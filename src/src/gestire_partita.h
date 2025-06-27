#ifndef GESTIRE_PARTITA_H_
#define GESTIRE_PARTITA_H_

#include "costanti.h"
#include "costanti_interfacce.h"
#include "messaggi_errori.h"
#include "gestire_controlli.h"
#include "gestire_griglia_gioco.h"
#include "gestire_salvataggi.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/partita.h"
#include "tipi_di_dato/stringa.h"
#include "utilita.h"

void giocare_partita(partita partita_corrente);
void stampare_informazioni_utente(partita partita_corrente);
void stampare_schermata_di_gioco(partita partita_corrente);


#endif
