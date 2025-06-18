#include <stdio.h>

#include "utils.h"
#include "costanti.h"
#include "tipi_di_dato/partita.h"
#include "tipi_di_dato/stringa.h"

// La seguente funzione permette di calcolare il resto intero della divisione tra numeratore e denominatore
int calcolare_resto_intero (int numeratore, int denominatore) {
    int r;		//Resto intero della divisione 
    int q;		//Quoziente della divisione utile a calcplare il resto 

    q = 0;
    // calcolo del quoziente
    while (numeratore >= denominatore) 
    {
        q = q + 1;
        numeratore = numeratore - denominatore;
    }
    //Calcolo del resto
    r = numeratore - denominatore * q;
    return r;
}
// La seguente funzione permette di calcolare la radice quadrata intera di un numero
int calcolare_radice_quadrata (int radicando){
    int radice;             //Possibile radice quadrata intera
    int radice_quad;        //Quadrato di radice
    bool_t trovato;         //Indica se è stata trovata una radice esatta

    trovato = FALSO;
    radice = 2;
    radice_quad = radice * radice;
    while (radicando >= radice_quad && trovato == FALSO) {
        if (radice_quad == radicando) {
            trovato = VERO;
            radice = radice - 1; 
        } 
        radice = radice + 1;
        radice_quad = radice * radice;
        }
    if (trovato == FALSO) {
        radice = 0;
    }
    return radice;
}

//La seguente funzione permette di convertire le lettere passate in input in numeri
int convertire_lettera_in_numero(char lettera) {
	int numero;
	numero = -1; //Inizializza numero con -1

	if (lettera >= 'A' && lettera <= 'G') { //Effettua il controllo sulla lettera, deve essere essere un carattere che permette di ottenere un numero sottraendo 55
		numero = lettera - 55;
	} else if (lettera >= '0' && lettera <= '9') { //Effettua il controllo sulla lettera, deve essere un carattere che permette di ottenere un numero sottraendo 48
		numero = lettera - 48;
	}
	return numero;
}

// La seguente funzione permette di convertire i numeri passati da input in lettere
char convertire_numeri_in_lettere(int numero) {
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

	file_partita = fopen(stringa_leggere_array(nome_file_partita), "rb");
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

// Funzione che converte una lettera minuscola in maiuscola utilizzando i codici ASCII
char convertire_minuscolo_maiuscolo(char lettera) {
    char lettera_convertita;  // Carattere risultante dalla conversione


    lettera_convertita = lettera;

    // Controlliamo se il carattere Ã¨ una lettera minuscola
    if ((lettera_convertita >= CHAR_a) && (lettera_convertita <= CHAR_z)) {
        lettera_convertita = lettera - 32; // viene sottratto 32 poichè bisogna portare da lettera minuscola a maiuscola basandoci sull'ascii
    }

    // Restituiamo il carattere convertito
    return lettera_convertita;
}
