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
#include "utils.h"

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
	griglia_gioco.dimensione_griglia = 4;
	griglia_gioco.valori_griglia[0][0] = 0;
	griglia_gioco.valori_griglia[0][1] = 2;
	griglia_gioco.valori_griglia[0][2] = 3;
	griglia_gioco.valori_griglia[0][3] = 4;
	griglia_gioco.valori_griglia[1][0] = 0;
	griglia_gioco.valori_griglia[1][1] = 2;
	griglia_gioco.valori_griglia[1][2] = 3;
	griglia_gioco.valori_griglia[1][3] = 4;
	griglia_gioco.valori_griglia[2][0] = 0;
	griglia_gioco.valori_griglia[2][1] = 2;
	griglia_gioco.valori_griglia[2][2] = 3;
	griglia_gioco.valori_griglia[2][3] = 4;
	griglia_gioco.valori_griglia[3][0] = 0;
	griglia_gioco.valori_griglia[3][1] = 2;
	griglia_gioco.valori_griglia[3][2] = 3;
	griglia_gioco.valori_griglia[3][3] = 4;
	for (int i = 0; i < griglia_gioco.dimensione_griglia; ++i) {
		for(int j = 0; j < griglia_gioco.dimensione_griglia; ++j) {
			printf("[%d]", griglia_gioco.valori_griglia[i][j]);

		}
		printf("\n");
	}
	printf("\n");
	aggiornare_griglia(&griglia_gioco, 1, 0, 0);
	for (int i = 0; i < griglia_gioco.dimensione_griglia; ++i) {
			for(int j = 0; j < griglia_gioco.dimensione_griglia; ++j) {
				printf("[%d]", griglia_gioco.valori_griglia[i][j]);

			}
			printf("\n");
		}
		printf("\n");
	system("pause");*/

	return 0;
}
