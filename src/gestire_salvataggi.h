#ifndef GESTIRE_SALVATAGGI_H_
#define GESTIRE_SALVATAGGI_H_

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "costanti.h"
#include "messaggi_errori.h"
#include "tipi_di_dato\stringa.h"
#include "tipi_di_dato\partita.h"
#include "utilita.h"

#define CARTELLA_SALVATAGGI ".\\salvataggi\\"
#define ESTENSIONE_FILE ".bin"

bool_t caricare_partita(partita* partita_da_caricare);
char* rimuovere_estensione_file(stringa nome_file);
stringa* aprire_directory(DIR* directory);
stringa* leggere_directory(char* nome_directory);
int calcolare_n_file_salvati(char* nome_directory);
void salvare_partita(partita partita_da_salvare);
void stampare_interfaccia_carica_partita();

#endif
