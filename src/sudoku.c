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

	/*griglia griglia_gioco;
	griglia_gioco.dimensione_griglia = 9;
	azzerare_griglia(&griglia_gioco);
	impostazioni impostazioni_utente;
	impostazioni_utente.difficolta = DIFFICOLTA_STANDARD;
	impostazioni_utente.dimensione_griglia = 9;

	riempire_griglia(&griglia_gioco, impostazioni_utente);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d ", griglia_gioco.valori[i][j].valore);
		}
		printf("\n");
	}system("pause");*/
	return 0;
}
