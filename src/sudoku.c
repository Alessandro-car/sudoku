/*
 ============================================================================
 Name        : sudoku.c
 Author      : Alessandro Carella; Pietro Loparco; Pasquale Gesualdo; Francesco Andrisani; Luigi Grosso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "gestire_menu_principale.h"
#include "gestire_salvataggi.h"
#include "utilita.h"

int main(void) {
	stringa* partite_salvate;
	partite_salvate = creare_directory(CARTELLA_SALVATAGGI);
	abilitare_ANSI();
	abilitare_num_lock(1);
	menu_principale(partite_salvate);
	return 0;
}
