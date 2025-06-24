#ifndef UTILS_H_
#define UTILS_H_
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "tipi_di_dato/partita.h"
#include "tipi_di_dato/stringa.h"
#include "costanti.h"


#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

int calcolare_radice_quadrata (int radicando);
int calcolare_resto_intero (int numeratore, int denominatore);
int convertire_lettera_in_numero(char lettera);
char convertire_numeri_in_lettere(int numero);
char nascondere_input_utente();
char convertire_minuscolo_maiuscolo(char lettera);
void impostare_coordinate_cursore(int x, int y);
void pulire_schermo();
void nascondere_cursore();
void mostrare_cursore();
void disegnare_riquadro_interfaccia();
void abilitare_ANSI();
void stampare_centrato_colorato(char colore[], char stringa[], int dim_riquadro);
void stampare_colorato(char colore[], char stringa[]);
void stampare_carattere_colorato(char colore[], char c);
char* concatenare_due_stringhe(char* str1, char* str2);
void prendere_input_stringa_limitato(stringa* str, int dim_input, int x, int y);
char prendere_input_carattere_limitato(int x, int y);
#endif
