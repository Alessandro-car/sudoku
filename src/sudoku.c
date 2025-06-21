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
	griglia_gioco.dimensione_griglia = 4;
	griglia_gioco.valori_griglia[0][0] = 0;
	griglia_gioco.valori_griglia[0][1] = 0;
	griglia_gioco.valori_griglia[0][2] = 0;
	griglia_gioco.valori_griglia[0][3] = 0;
	griglia_gioco.valori_griglia[1][0] = 0;
	griglia_gioco.valori_griglia[1][1] = 0;
	griglia_gioco.valori_griglia[1][2] = 0;
	griglia_gioco.valori_griglia[1][3] = 0;
	griglia_gioco.valori_griglia[2][0] = 0;
	griglia_gioco.valori_griglia[2][1] = 0;
	griglia_gioco.valori_griglia[2][2] = 0;
	griglia_gioco.valori_griglia[2][3] = 0;
	griglia_gioco.valori_griglia[3][0] = 0;
	griglia_gioco.valori_griglia[3][1] = 0;
	griglia_gioco.valori_griglia[3][2] = 0;
	griglia_gioco.valori_griglia[3][3] = 0;
	impostazioni impostazioni_utente;
	impostazioni_utente.dimensione_griglia = 4;
	impostazioni_utente.difficolta = DIFFICOLTA_STANDARD;
	riempire_griglia(&griglia_gioco, impostazioni_utente);
	for (int i = 0; i < griglia_gioco.dimensione_griglia; ++i) {
			for(int j = 0; j < griglia_gioco.dimensione_griglia; ++j) {
				printf("[%d]", griglia_gioco.valori_griglia[i][j]);

			}
			printf("\n");
		}
	printf("\n");
	coordinata* valori_non_mod = prendere_coordinate_valori(griglia_gioco, impostazioni_utente);
	int n_numeri_non_mod = n_numeri_di_griglia(impostazioni_utente);
	for (int i = 0; i < n_numeri_non_mod; ++i) {
		printf("[%d;%d]\n", coordinata_leggere_riga(valori_non_mod[i]), coordinata_leggere_colonna(valori_non_mod[i]));
	}

	system("pause");*/
	return 0;
}
