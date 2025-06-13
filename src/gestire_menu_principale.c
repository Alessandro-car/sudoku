#include "gestire_menu_principale.h"
#include "griglia.h"
#include "impostazioni.h"
#include "partita.h"
#include "stringa.h"

void stampare_interfaccia_menu_principale() {
	printf("%*s| SUDOKU |\n", 		34, "");
	printf("%*s+--------+\n", 		34, "");
	printf("\n\n\n\n\n\n\n\n");
	printf("%*s\t 1. Inizia partita\n", 		31, "");
	printf("%*s\t 2. Carica partita\n", 		31, "");
	printf("%*s\t 3. Esci", 	31, "");
}


stringa *iniziare_partita(impostazioni impostazioni_gioco, int difficolta_scelta, int dim_griglia_scelta, stringa nome_partita, partita partita) {

	stringa *nome_file_partita;
	griglia griglia_sudoku;
	char comando_utente;

	do {
		printf(interfaccia_menu_opzioni);
		scanf("%c", &comando_utente);
		if(comando_utente == '1') {
			difficolta_scelta = selezionare_difficolta(difficolta_scelta);
		}
		if(comando_utente == '2') {
			dim_griglia_scelta = selezionare_dimensione_griglia(dim_griglia_scelta);
		}
		if(comando_utente == '3') {
			scanf("%s", &nome_partita);
		}
		if(comando_utente == '4') {
			impostazioni_di_gioco = impostare_parametri_di_gioco(impostazioni_di_gioco, difficolta_scelta, dim_griglia_scelta)
			griglia_sudoku = inizializzare_griglia(impostazioni_di_gioco);
			partita = inizializzare_partita(impostazioni_di_gioco, griglia_sudoku, nome_partita, partita);
			*partite_salvate = giocare_partita(partita);
		}
	} while(comando_utente != '4' || comando_utente != '5');
	return *nome_file_partita;
}


partita caricare_partita(stringa *partite_salvate) {

	FILE *file_scelto;
	char comando_utente;
	partita partita_caricata;

	printf(interfaccia_partite_scelte);
	scanf("%c", comando_utente);

	//file_scelto = partite_salvate[comando_utente];


	if()
}

