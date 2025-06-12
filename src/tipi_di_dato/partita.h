#ifndef PARTITA_H_
#define PARTITA_H_

#include "impostazioni.h"
#include "griglia.h"
#include "stringa.h"

typedef struct {
	impostazioni impostazioni_partita;
	griglia griglia_partita;
	stringa nome_partita;
} partita;

impostazioni partita_leggere_impostazioni(partita var_partita);
void partita_scrivere_impostazioni(partita* var_partita, impostazioni nuove_impostazioni);
griglia partita_leggere_griglia(partita var_partita);
void partita_scrivere_griglia(partita* var_partita, griglia nuova_griglia);
stringa partita_leggere_nome(partita var_partita);
void partita_scrivere_nome(partita* var_partita, stringa nuovo_nome);

#endif

