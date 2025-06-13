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

void menu_scelta_difficolta() {
	/*for (int i = 0; i < 80; i++) {
	    putchar('-');
	}
	putchar('\n');*/
	printf("%*s| DIFFICOLTA |\n", 		33, "");
	printf("%*s+------------+\n", 		33, "");
	printf("\n\n\n\n\n\n"); //9^ riga
	printf("%*s\t 1. Facile\n\n", 		27, "");
	printf("%*s\t 2. Medio\n\n", 		27, "");
	printf("%*s\t 3. Difficile\n\n", 	27, "");
	printf("%*s\t 4. Info\n\n", 		27, "");
	printf("%*s\t 5. Indietro\n\n", 	27, "");

	printf("\n\n\n\n\n\n\n");

}

void inizializzare_partita(impostazioni impostazioni_utente, griglia griglia, stringa nome_partita, partita *partita) {
	  partita_scrivere_impostazioni(partita, impostazioni_utente);
    partita_scrivere_griglia(partita, griglia);
    partita_scrivere_nome(partita, nome_partita);

    return;
}
