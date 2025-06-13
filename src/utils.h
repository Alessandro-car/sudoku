#ifndef UTILS_H_
#define UTILS_H_

#include "tipi_di_dato/partita.h"

typedef enum {
	TRUE,
	FALSE
} bool_t;

int convertire_lettera_in_numero(char lettera);
char convertire_numeri_in_lettere(int numero);
partita caricare_partita_da_file(stringa nome_file_partita);
int nascondere_input_utente();

#endif
