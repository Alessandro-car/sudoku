#include "utilita.h"

char* concatenare_due_stringhe(char* str1, char* str2) {
	char* stringa_finale;
	stringa_finale = calloc(strlen(str1) + strlen(str2) + 1, sizeof(char));
	strcpy(stringa_finale, str1);
	strcat(stringa_finale, str2);
	stringa_finale[strlen(str1) + strlen(str2) + 1] = '\0';
	return stringa_finale;
}

char convertire_minuscolo_maiuscolo(char lettera) {
    char lettera_convertita;  // Carattere risultante dalla conversione


    lettera_convertita = lettera;

    // Controlliamo se il carattere e' una lettera minuscola
    if ((lettera_convertita >= CHAR_a) && (lettera_convertita <= CHAR_z)) {
        lettera_convertita = lettera - 32; // viene sottratto 32 poichè bisogna portare da lettera minuscola a maiuscola basandoci sull'ascii
    }

    // Restituiamo il carattere convertito
    return lettera_convertita;
}

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

char nascondere_input_utente() {
	char comando_utente;
	nascondere_cursore();
	printf("\033[8m");
	comando_utente = getch();
	printf("\033[0m");
	fflush(stdout);
	return comando_utente;
}

char prendere_input_carattere_limitato(int x, int y) {
	int i;
	char c;
	char val;

	i = 0;
	c = '\0';
	val = '\0';
	while (c != TASTO_INVIO) {
		c = getch();
		if (c == TASTO_BACKSPACE && i > 0) {
			i = i - 1;
			val = '\0';
		} else if (i < 1 && c != TASTO_BACKSPACE) {
			i = i + 1;
			val = c;
		}
		impostare_coordinate_cursore(x, y);
		printf("%*c", 2, ' ');
		impostare_coordinate_cursore(x, y);
		printf("%c", val);
	}
	return val;
}

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

int calcolare_resto_intero(int numeratore, int denominatore) {
	while (numeratore >= denominatore)
	{
		numeratore = numeratore - denominatore;
	}
	return numeratore;
}

int convertire_lettera_in_numero(char lettera) {
	int numero;
	numero = -1;

	if (lettera >= 'A' && lettera <= 'G') {
		numero = lettera - 55;
	} else if (lettera >= '0' && lettera <= '9') {
		numero = lettera - 48;
	}
	return numero;
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
	return;
}

void impostare_coordinate_cursore(int x, int y) {
	printf("\033[%d;%dH", y, x);
	return;
}

void mostrare_cursore() {
	printf("\033[?25h");
	return;
}

void nascondere_cursore() {
	printf("\033[?25l");
	return;
}

void prendere_input_stringa_limitato(stringa* str, int dim_input, int x, int y) {
	int i;
	char c;

	i = 0;
	c = '\0';
	stringa_scrivere_dimensione(str, 0);
	while (c != TASTO_INVIO) {
		c = getch();
		if (c == TASTO_BACKSPACE && i > 0) {
			i = i - 1;
			stringa_scrivere_carattere(str, i, '\0');
		} else if (i < dim_input && c != TASTO_BACKSPACE) {
			stringa_scrivere_carattere(str, i, c);
			i = i + 1;
		}
		stringa_scrivere_dimensione(str, i);
		impostare_coordinate_cursore(x, y);
		printf("%*c", dim_input, ' ');
		impostare_coordinate_cursore(x, y);
		printf("%s", stringa_leggere_array(*str));
	}
	if (i < dim_input) {
		stringa_scrivere_dimensione(str, i - 1);
	}
	stringa_scrivere_carattere(str, i, '\0');
	return;
}

void pulire_schermo() {
	system("@cls||clear");
	return;
}

void stampare_banner_errore(int x, int y, int dim, char* messaggio_errore) {
	int i;
	i = 1;
	while (i < dim - 2) {
		impostare_coordinate_cursore(x + i, y - 1);
		printf("-");
		i = i + 1;
	}

	impostare_coordinate_cursore(x + 1, y);
	stampare_centrato_colorato(COLORE_ANSI_ROSSO, messaggio_errore, dim);

}

void stampare_carattere_colorato(char colore[], char c) {
	printf("%s%c%s", colore, c, COLORE_ANSI_RESET);
	return;
}

void stampare_centrato_colorato(char colore[], char stringa[], int dim_riquadro) {
	int n_spazi;
	n_spazi = dim_riquadro / 2 - strlen(stringa) / 2 - 2;
	printf("%s%*c%s%*c%s", colore, n_spazi, ' ', stringa, n_spazi, ' ', COLORE_ANSI_RESET);
}

void stampare_colorato(char colore[], char stringa[]) {
	printf("%s%s%s", colore, stringa, COLORE_ANSI_RESET);
	return;
}




