/*
 ============================================================================
 Name        : sudoku.c
 Author      : Alessandro Carella; Pietro Loparco; Pasquale Gesualdo; Francesco Andrisani; Luigi Grosso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "gestire_errori.h"

//TODO: DA CONSIDERARE SE ORDINARE GLI IMPORT, LE DICHIARAZIONI E LE DISPOSIZIONI DELLE FUNZIONI IN ORDINE ALFABETICO
//TODO: SISTEMARE GLI IMPORT SOLO NEI FILE.h
//TODO: CAMBIARE NOME AL FILE UTILS
//TODO: SISTEMARE I COMMENTI

int main(void) {
	abilitare_ANSI();
	stringa* partite_salvate;
	partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));
	partite_salvate = menu_principale();
	/*pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_banner_errore(1, 24, 80, ERRORE_NOME_FILE);
	printf("\n\n");
	system("pause");*/
	return 0;
}
