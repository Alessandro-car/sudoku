/*
 ============================================================================
 Name        : sudoku.c
 Author      : Alessandro Carella; Pietro Loparco; Pasquale Gesualdo; Francesco Andrisani; Luigi Grosso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gestire_partita.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/impostazioni.h"
#include "gestire_griglia_gioco.h"
#include "gestire_salvataggi.h"
#include "utils.h"
#include "costanti.h"

//TODO: DA CONSIDERARE SE ORDINARE GLI IMPORT, LE DICHIARAZIONI E LE DISPOSIZIONI DELLE FUNZIONI IN ORDINE ALFABETICO
//TODO: SISTEMARE GLI IMPORT SOLO NEI FILE.h
//TODO: CAMBIARE NOME AL FILE UTILS
//TODO: SISTEMARE I COMMENTI

int main(void) {
	abilitare_ANSI();
	stringa* partite_salvate;
	partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));
	partite_salvate = menu_principale();
	return 0;
}
