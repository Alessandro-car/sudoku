#ifndef UTILS_H_
#define UTILS_H_
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "tipi_di_dato/partita.h"
#include "costanti.h"
#include "tipi_di_dato/partita.h"
#include "tipi_di_dato/stringa.h"

typedef enum {
	FALSO,
	VERO
} bool_t;

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

int calcolare_radice_quadrata (int radicando);
int calcolare_resto_intero (int numeratore, int denominatore);
int convertire_lettera_in_numero(char lettera);
char convertire_numeri_in_lettere(int numero);
partita caricare_partita_da_file(stringa nome_file_partita);
char nascondere_input_utente();
char convertire_minuscolo_maiuscolo(char lettera);
void impostare_coordinate_cursore(int x, int y);
void pulire_schermo();
void nascondere_cursore();
void mostrare_cursore();
void disegnare_riquadro_interfaccia();
void abilitare_ANSI();
#endif
