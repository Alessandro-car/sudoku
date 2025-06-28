#ifndef GESTIRE_SALVATAGGI_H_
#define GESTIRE_SALVATAGGI_H_

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "costanti.h"
#include "costanti_interfacce.h"
#include "messaggi_errori.h"
#include "utilita.h"
#include "tipi_di_dato\stringa.h"
#include "tipi_di_dato\partita.h"

#define CARTELLA_SALVATAGGI ".\\salvataggi\\"
#define ESTENSIONE_FILE ".bin"
#define CARATTERI_NOME_FILE_NON_AMMESSI "/<>:\"\\|?*"

bool_t caricare_partita(partita* partita_da_caricare);
char* rimuovere_estensione_file(stringa nome_file);
stringa* aprire_directory(DIR* directory);
stringa* creare_directory(char* nome_directory);
int calcolare_n_file_salvati(char* nome_directory);
stringa* salvare_partita(partita partita_da_salvare);
void stampare_riquadro_informazioni_partita(int x, int y, char* file_path);
void stampare_interfaccia_carica_partita();

#endif
