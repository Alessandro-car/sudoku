#ifndef UTILITA_H_
#define UTILITA_H_

#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include "costanti.h"
#include "costanti_interfacce.h"
#include "tipi_di_dato/stringa.h"


#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

char* concatenare_due_stringhe(char* str1, char* str2);
char convertire_minuscolo_maiuscolo(char lettera);
char convertire_numeri_in_lettere(int numero);
char nascondere_input_utente();
char prendere_input_carattere_limitato(int x, int y);

int calcolare_radice_quadrata (int radicando);
int calcolare_resto_intero (int numeratore, int denominatore);
int convertire_lettera_in_numero(char lettera);

void abilitare_ANSI();
void disegnare_riquadro_interfaccia();
void impostare_coordinate_cursore(int x, int y);
void mostrare_cursore();
void nascondere_cursore();
void prendere_input_stringa_limitato(stringa* str, int dim_input, int x, int y);
void pulire_schermo();
void stampare_banner_errore(int x, int y, int dim, char* messaggio_errore);
void stampare_carattere_colorato(char colore[], char c);
void stampare_centrato_colorato(char colore[], char stringa[], int dim_riquadro, int y);
void stampare_colorato(char colore[], char stringa[]);
void stampare_carattere_colorato_rgb(int r, int g, int b, char c);
void stampare_colorato_rgb(int r, int g, int b, char stringa[]);

#endif
