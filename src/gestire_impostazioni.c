#include <stdio.h>

#include "gestire_impostazioni.h"
#include "costanti.h"
#include "tipi_di_dato/impostazioni.h"
#include "utils.h"

int selezionare_dimensione_griglia() {
	printf("%*s| DIMENSIONE | %*s\n", 33, "", 33, "");
	printf("%*s+------------+%*s", 33, "", 33, "");
	printf("\n\n\n\n\n\n\n");
	printf("%*s1. Piccola:  4 \u00D7 4%*s", 31, "", 31, "");
	printf("\n%*s2. Standard: 9 \u00D7 9%*s", 31, "", 31, "");
	printf("\n%*s3. Grande:   16 \u00D7 16%*s", 31, "", 31, "");
	printf("\n%*s4. Torna indietro%*s", 31, "", 31, "");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	int comando_utente;
	comando_utente = nascondere_input_utente();
	int dim_griglia_scelta;
	dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	if (comando_utente == '1') {
		dim_griglia_scelta = DIM_GRIGLIA_PICCOLA;
	}
	if (comando_utente == '2') {
		dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	}
	if (comando_utente == '3') {
		dim_griglia_scelta = DIM_GRIGLIA_GRANDE;
	}
	return dim_griglia_scelta;
}

void impostare_parametri_di_gioco(impostazioni* impostazioni_gioco, int difficolta_scelta, int dim_griglia_scelta) {
	impostazioni_scrivere_difficolta(impostazioni_gioco, difficolta_scelta);
	impostazioni_scrivere_dimensione_griglia(impostazioni_gioco,dim_griglia_scelta);
}
