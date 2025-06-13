#include <stdio.h>

#include "utils.h"
#include "tipi_di_dato/griglia.h"
#include "costanti.h"

int selezionare_dimensione_griglia();

int main() {
	int dim_griglia = selezionare_dimensione_griglia();
}

bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione) {
	bool_t corretto = TRUE;
	int i = riga;
	while (i < riga + dimensione_regione) {
		int j = colonna;
		while ( j < colonna + dimensione_regione) {
			if (griglia_leggere_valore(griglia, i, j) == numero_da_inserire) {
				corretto = FALSE;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return corretto;
}

bool_t validare_riga_input(int riga, int dim_griglia) {
	bool_t validato = TRUE;
	if (riga < 0 || riga > dim_griglia) {
		validato = FALSE;
	}
	return validato;
}

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
	printf("\033[8m");
	comando_utente = getchar();
	printf("\033[0m");
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
