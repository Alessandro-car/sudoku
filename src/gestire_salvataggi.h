#ifndef GESTIRE_SALVATAGGI_H_
#define GESTIRE_SALVATAGGI_H_

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "utils.h"
#include "costanti.h"
#include "tipi_di_dato\stringa.h"
#include "tipi_di_dato\partita.h"

#define CARTELLA_SALVATAGGI ".\\salvataggi\\"
#define ESTENSIONE_FILE ".bin"

int calcolare_n_file_salvati(char* nome_directory);
stringa* apri_directory(DIR* directory);
stringa* leggere_directory(char* nome_directory);
char* rimuovere_estensione_file(stringa nome_file);
void stampare_interfaccia_carica_partita();
void salvare_partita(partita partita_da_salvare);
bool_t caricare_partita(partita* partita_da_caricare);

#endif
