#include <stdio.h>

#include "utils.h"
#include "costanti.h"
#include "tipi_di_dato/partita.h"

int convertire_lettera_in_numero(char lettera) {
	//La seguente funzione permette di convertire le lettere passate in input in numeri
		int numero;
		numero = -1; //Inizializza numero con -1

		if (lettera >= 'A' && lettera <= 'G') { //Effettua il controllo sulla lettera, deve essere essere un carattere che permette di ottenere un numero sottraendo 55
			numero = lettera - 55;
		} else if (lettera >= '0' && lettera <= '9') { //Effettua il controllo sulla lettera, deve essere un carattere che permette di ottenere un numero sottraendo 48
			numero = lettera - 48;
		}
		return numero;
}

char convertire_numeri_in_lettere(int numero) {
// La seguente funzione permette di convertire i numeri passati da input in lettere
	char lettera;

	lettera = ' '; //Inizializza il carattere in un carattere vuoto
	if(numero >= 10 && numero<= DIM_GRIGLIA_GRANDE) { // Effettua il controllo sul numero, deve rispettare i vincoli
		lettera = numero + 55; // Somma al numero passato da input "55", questo permette di trasformarlo nella lettera corrispondente mediante ASCII
	}
	if(numero >= 0 && numero <= 9){
		lettera = numero + 48;
	}
	return lettera;
}

partita caricare_partita_da_file(stringa nome_file_partita) {
	FILE* file_partita;
	partita partita_caricata;
	file_partita = fopen(nome_file_partita.caratteri, "rb");
	fread(&partita_caricata.nome_partita, sizeof(stringa), 1, file_partita);
	fread(&partita_caricata.griglia_partita, sizeof(griglia), 1 , file_partita);
	fread(&partita_caricata.impostazioni_partita, sizeof(impostazioni), 1, file_partita);
	fclose(file_partita);
	return partita_caricata;
}

int nascondere_input_utente() {
	int comando_utente;
	printf("\033[8m");
	comando_utente = getchar();
	printf("\033[0m");

	return comando_utente;
}
