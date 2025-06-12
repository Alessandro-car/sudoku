#include "utils.h"
#include "costanti.h"

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
	if(numero >= 10 && numero<= DIMENSIONE_GRIGLIA_GRANDE) { // Effettua il controllo sul numero, deve rispettare i vincoli
		lettera = numero + 55; // Somma al numero passato da input "55", questo permette di trasformarlo nella lettera corrispondente mediante ASCII
	}
	if(numero >= 0 && numero <= 9){
		lettera = numero + 48;
	}
	return lettera;
}
