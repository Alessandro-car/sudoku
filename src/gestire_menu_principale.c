#include <stdio.h>
#include <stdlib.h>

#include "gestire_menu_principale.h"
#include "costanti.h"
#include "tipi_di_dato/griglia.h"
#include "gestire_impostazioni.h"
#include "tipi_di_dato/impostazioni.h"
#include "utils.h"

void stampare_interfaccia_menu_principale() {
	printf("%*s| SUDOKU |\n", 		34, "");
	printf("%*s+--------+\n", 		34, "");
	printf("\n\n\n\n\n\n\n\n");
	printf("%*s\t 1. Inizia partita\n", 		31, "");
	printf("%*s\t 2. Carica partita\n", 		31, "");
	printf("%*s\t 3. Esci", 	31, "");
}


stringa* menu_principale() {
	int comando_utente;
	int difficolta_scelta;
	int dim_griglia_scelta;
	impostazioni impostazioni_gioco;
	stringa* nome_partite_salvate;

	stampare_interfaccia_menu_principale();
	comando_utente = nascondere_input_utente();
	nome_partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));

	do {

		if (comando_utente == '1') {
			difficolta_scelta = DIFFICOLTA_STANDARD;
			dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
			impostazioni_scrivere_dimensione_griglia(&impostazioni_gioco, dim_griglia_scelta);
			impostazioni_scrivere_difficolta(&impostazioni_gioco, difficolta_scelta);
			//nome_partite_salvate = iniziare_partita(impostazioni_gioco, difficolta_scelta, difficolta_scelta, stringa nome_partita, partita partita)
		}
		if (comando_utente == '2') {
			partita partita_caricata;
			partita_caricata = caricare_partita(nome_partite_salvate);
			//nome_partite_salvate = giocare_partita(partita_caricata);
		}
	} while(comando_utente != '3');
	return nome_partite_salvate;
}

stringa* iniziare_partita(impostazioni impostazioni_gioco, int difficolta_scelta, int dim_griglia_scelta, stringa nome_partita, partita partita) {

	stringa *nome_file_partita;
	griglia griglia_sudoku;
	int comando_utente;

	do {
		//TODO: Interfaccia menu opzioni
		//printf(interfaccia_menu_opzioni);
		comando_utente = nascondere_input_utente();
		if(comando_utente == '1') {
			 //TODO: Funzione per selezionare la difficolta
			 //difficolta_scelta = selezionare_difficolta(difficolta_scelta);
		}
		if(comando_utente == '2') {
			dim_griglia_scelta = selezionare_dimensione_griglia(dim_griglia_scelta);
		}
		if(comando_utente == '3') {
			//TODO: Aggiustare l'input
			//scanf("%s", &nome_partita.caratteri);
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


partita caricare_partita(stringa* partite_salvate) {
	stringa nome_file_scelto;
	int comando_utente;
	partita partita_caricata;

	//printf(interfaccia_caricare_partita);
	comando_utente = nascondere_input_utente();
	//file_scelto = partite_salvate[comando_utente];
	//TODO: Controllo se il numero di partite salvate e' > 0

	nome_file_scelto = partite_salvate[comando_utente];
	partita_caricata = caricare_partita_da_file(nome_file_scelto);
	return partita_caricata;
}

