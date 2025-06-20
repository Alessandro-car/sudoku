#include "utils.h"

//TODO: Cambiare lo pseudo
// La seguente funzione permette di calcolare il resto intero della divisione tra numeratore e denominatore
int calcolare_resto_intero(int numeratore, int denominatore) {
	// calcolo del quoziente
	while (numeratore > denominatore)
	{
		numeratore = numeratore - denominatore;
	}
	return numeratore;
}
// La seguente funzione permette di calcolare la radice quadrata intera di un numero
int calcolare_radice_quadrata(int radicando){
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
	//fread(&partita_caricata.griglia_partita, sizeof(griglia), 1 , file_partita);
	fread(&partita_caricata.impostazioni_partita, sizeof(impostazioni), 1, file_partita);
	fclose(file_partita);
	return partita_caricata;
}

char nascondere_input_utente() {
	char comando_utente;
	nascondere_cursore();
	printf("\033[8m");
	comando_utente = getch();
	printf("\033[0m");
	fflush(stdout);
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

void impostare_coordinate_cursore(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void pulire_schermo() {
	system("@cls||clear");
}

void nascondere_cursore() {
	printf("\033[?25l");
}

void mostrare_cursore() {
	printf("\033[?25h");
}


void disegnare_riquadro_interfaccia() {
	int i;
	i = 0;
	while (i < LARGHEZZA_FINESTRA) {
		int j;
		j = 0;
		while (j <= LUNGHEZZA_FINESTRA) {
			if ((j == 0 || j == LUNGHEZZA_FINESTRA)) {
				impostare_coordinate_cursore(i, j);
				printf("-");
			} else {
				if ((i == 0 || i == LARGHEZZA_FINESTRA - 1)) {
					impostare_coordinate_cursore(i, j);
					printf("|");
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}
	impostare_coordinate_cursore(0, 0);
	printf("+");
	impostare_coordinate_cursore(0, LUNGHEZZA_FINESTRA);
	printf("+");
	impostare_coordinate_cursore(LARGHEZZA_FINESTRA - 1, 0);
	printf("+");
	impostare_coordinate_cursore(LARGHEZZA_FINESTRA - 1, LUNGHEZZA_FINESTRA);
	printf("+");
}

void abilitare_ANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (hOut == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    return;
}

void stampare_colorato(char colore[], char stringa[]) {
	printf("%s%s%s", colore, stringa, COLORE_ANSI_RESET);
	return;
}

void stampare_carattere_colorato(char colore[], char c) {
	printf("%s%c%s", colore, c, COLORE_ANSI_RESET);
}
