#include "utilita.h"

/*	Funzione: controllare_caratteri_stringa()
 * 	Descrizione: Questa funzione controlla se una stringa contiene almeno uno della stringa di caratteri da controllare
 * 	Parametri:
 * 		-str, stringa da controllare
 * 		-caratteri_da_controllare, array di caratteri da controllare se almeno uno di essi è presente in str
 *	Dato di ritorno:
 *		-esito, booleano che indica se str contiene almeno uno dei caratteri dati
 */
bool_t controllare_caratteri_stringa(stringa str, char* caratteri_da_controllare) {
	bool_t esito;
	int i; 				//Indice di str
	int j; 				//Indice di caratteri_da_controllare

	esito = VERO;
	i = 0;
	while (i < calcolare_lunghezza_stringa(caratteri_da_controllare) && esito != FALSO) {
		j = 0;
		while (j < stringa_leggere_dimensione(str) && esito != FALSO) {
			if (stringa_leggere_carattere(str, j) == *(caratteri_da_controllare + i) ||
				stringa_leggere_carattere(str, j) < 0 ||
				stringa_leggere_carattere(str, j) > 127
			) {
				esito = FALSO;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return esito;
}

/*	Funzione: concatenare_due_stringhe()
 * 	Descrizione: Questa funzione concatena due array di caratteri passati in input
 * 	Parametri:
 * 		-str1, primo array di caratteri da concatenare
 * 		-str2, secondo array di caratteri da concatenare
 *	Dato di ritorno:
 *		-stringa_finale, array di caratteri con str1 e str2 concatenate
 */
char* concatenare_due_stringhe(char* str1, char* str2) {
	int i; 					//Indice di str1
	int j;					//Indice di str2
	char* stringa_finale;	//Array di caratteri finale
	//La lunghezza di stringa_finale è data dalla lunghezza di str1 + la lunghezza di str2 + 1 per il null byte
	stringa_finale = calloc(calcolare_lunghezza_stringa(str1) + calcolare_lunghezza_stringa(str2) + 1, sizeof(char));
	i = 0;
	while (i < calcolare_lunghezza_stringa(str1)) {
		stringa_finale[i] = str1[i];
		i = i + 1;
	}
	j = 0;
	while (j < calcolare_lunghezza_stringa(str2)) {
		stringa_finale[i + j] = str2[j];
		j = j + 1;
	}
	stringa_finale[i + j] = '\0';
	return stringa_finale;
}

/*	Funzione: convertire_minuscolo_maiuscolo()
 * 	Descrizione: Questa funzione converte una lettera minuscola nella corrispondente in maiuscolo
 * 	Parametri:
 * 		-lettera, lettera da convertire
 *	Dato di ritorno:
 *		-lettera_convertita, 'lettera' convertita da minuscolo a maiuscolo
 */
char convertire_minuscolo_maiuscolo(char lettera) {
    char lettera_convertita;
    lettera_convertita = lettera; //Se 'lettera' non è una lettera dell'alfabeto allora la funzione restituisce il carattere stesso

    // Controlliamo se il carattere e' una lettera minuscola
    if ((lettera_convertita >= CHAR_a) && (lettera_convertita <= CHAR_z)) {
        lettera_convertita = lettera - 32; // Viene sottratto 32 poichè bisogna portare da lettera minuscola a maiuscola basandoci sui codici ASCII
    }

    return lettera_convertita;
}

/*	Funzione: convertire_numeri_in_lettere()
 * 	Descrizione: Questa funzione converte un numero compreso nell'intervallo [0, 16] nella lettera corrispondente.
 * 	Parametri:
 * 		-numero, numero da convertire in carattere
 *	Dato di ritorno:
 *		-lettera, carattere corrispondente al numero convertito
 */
char convertire_numeri_in_lettere(int numero) {
	char lettera;

	lettera = ' '; //Inizializza il carattere in un carattere vuoto
	if(numero >= 10 && numero <= DIM_GRIGLIA_GRANDE) {
		lettera = numero + 55; // Somma 55 al numero passato da input e la lettera corrispondente è nell'intervallo ['A', 'G']
	} else if(numero >= 0 && numero <= 9){
		lettera = numero + 48; // Somma 48 al numero passato da input e la lettera corrispondente è nell'intervallo ['0', '9']
	}
	return lettera;
}

/*	Funzione: nascondere_input_utente()
 * 	Descrizione: Questa funzione prende in input un carattere da tastiera ma non lo stampa a video e ne nasconde anche il cursore
 * 	Parametri:
 *	Dato di ritorno:
 *		-comando_utente, carattere inserito dall'utente
 */
char nascondere_input_utente() {
	char comando_utente;
	nascondere_cursore();
	comando_utente = getch();
	fflush(stdout);
	return comando_utente;
}

/*	Funzione: prendere_input_carattere_limitato()
 * 	Descrizione: Questa funzione permette di leggere un solo carattere da tastiera, stamparlo a video e aspettare l'invio da parte dell'utente.
 * 	Questa funzione è stata creata in quanto la funzione getch() non stampa a video il carattere inserito, la funzione getchar() e scanf(),
 * 	stampano a video tutti i caratteri fino a quando non viene premuto INVIO.
 * 	Parametri:
 *		-x, y: coordinate dove stampare sul terminale l'inserimento del carattere da parte dell'utente.
 *	Dato di ritorno:
 *		-val, carattere inserito dall'utente
 */
char prendere_input_carattere_limitato(int x, int y) {
	int i;
	int c;
	char val;

	i = 0;
	c = 0;
	val = '\0';
	while (c != TASTO_INVIO) {
		c = leggere_carattere();
		if (c != FRECCIA_SX &&
			c != FRECCIA_DX &&
			c != FRECCIA_SU &&
			c != FRECCIA_GIU
		) {
			if (c == TASTO_BACKSPACE && i > 0) {
				i = i - 1;
				val = '\0';
			} else if (i < 1 && c != TASTO_BACKSPACE && c != TASTO_ESC) {
				i = i + 1;
				val = c;
			}
			impostare_coordinate_cursore(x, y);
			printf("%*c", 2, ' ');
			impostare_coordinate_cursore(x, y);
			printf("%c", val);
		}
	}
	return val;
}

/*	Funzione: calcolare_radice_quadrata()
 * 	Descrizione: Questa funzione permette di calcolare la radice quadrata di un numero
 * 	Parametri:
 * 		-radicando, numero del quale calcolarne la radice quadrata
 *	Dato di ritorno:
 *		-radice, radice quadrata del numero passato in input
 */
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

/*	Funzione: calcolare_resto_intero()
 * 	Descrizione: Questa funzione implementa l'operatore modulo, quindi calcola la parte intera di una divisione fra due numeri
 * 	Parametri:
 * 		-numeratore, numeratore della divisione
 * 		-denominatore, denominatore della divisione
 *	Dato di ritorno:
 *		-numeratore, parte intera del resto calcolato nella divisione tra i due numeri
 */
int calcolare_resto_intero(int numeratore, int denominatore) {
	while (numeratore >= denominatore)
	{
		numeratore = numeratore - denominatore;
	}
	return numeratore;
}

/*	Funzione: convertire_lettera_in_numero()
 * 	Descrizione: Questa funzione prende converte un carattere nell'intervallo ['0', '9'] o ['A', 'G'] in un numero nell'intervallo ['A', 'G']
 * 	Parametri:
 * 		-lettera, carattere da convertire in numero
 *	Dato di ritorno:
 *		-numero, numero corrispondente del carattere passato in input
 */
int convertire_lettera_in_numero(char lettera) {
	int numero;
	numero = -1; 		//Questa funzione restituisce -1 se il carattere non è in uno dei due intervalli descritti

	if (lettera >= 'A' && lettera <= 'G') {
		numero = lettera - 55;
	} else if (lettera >= '0' && lettera <= '9') {
		numero = lettera - 48;
	}
	return numero;
}

/*	Funzione: calcolare_lunghezza_stringa()
 * 	Descrizione: Questa funzione permette di calcolare la dimensione di un array di caratteri
 * 	Parametri:
 * 		-str: array di caratteri del quale calcolarne la dimensione
 *	Dato di ritorno:
 *		-dim: dimensione dell'array di caratteri
 */
int calcolare_lunghezza_stringa(char* str) {
	int dim; 			//Indice della stringa e rispettiva dimensione
	dim = 0;
	while (str[dim] != '\0') {
		dim = dim + 1;
	}
	return dim;
}

/*	Funzione: leggere_carattere()
 * 	Descrizione: Questa funzione permette di leggere un carattere da tastiera e individua se sono state premute delle freccette.
 * 	Le freccette sono riconosciute da due sequenze di valori esadecimali e sono le seguenti:
 * 		-Freccia SU:  0xE0 0x48
 * 		-Freccia GIU: 0xE0 0x50
 * 		-Freccia SX:  0xE0 0x4B
 * 		-Freccia DX:  0xE0 0x4D
 * 	Dato di ritorno:
 *		-c: carattere letto da tastiera
 */
int leggere_carattere() {
	int c;
	c = getch();
	if (c == 0xE0) {
		c = getch();
		if (c == 0x4B) {
			c = FRECCIA_SX;
		}
		else if (c == 0x4D) {
			c = FRECCIA_DX;
		}
		else if (c == 0x50) {
			c = FRECCIA_GIU;
		}
		else if (c == 0x48) {
			c = FRECCIA_SU;
		}
	}
	return c;
}

/*	Funzione: abilitare_ANSI()
 * 	Descrizione: Questa funzione permette di abilitare i codici ANSI nella cmd.
 */
void abilitare_ANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (hOut == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    dwMode |= ENABLE_PROCESSED_INPUT;
    SetConsoleMode(hOut, dwMode);
    return;
}

/*	Funzione: abilitare_num_lock()
 * 	Descrizione: Questa funzione permette di abilitare il tastierino numerico.
 * 	Questa funzione serve in quanto, se disattivato, da problemi nell'input.
 */
void abilitare_num_lock(int stato) {
	int stato_corrente;
	stato_corrente = GetKeyState(VK_NUMLOCK) & 1;

	if (stato_corrente != stato) {
		keybd_event(VK_NUMLOCK, 0, 0, 0);
		keybd_event(VK_NUMLOCK, 0, KEYEVENTF_KEYUP, 0);
	}
}

/*	Funzione: disegnare_riquadro_interfaccia()
 *	Descrizione: Questa funzione stampa il riquadro della finestra
 */
void disegnare_riquadro_interfaccia() {
	int i; 				//Indice delle colonne del cursore
	int j;				//Indice delle righe del cursore
	i = 0;
	while (i < LARGHEZZA_FINESTRA) {
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

/*	Funzione: impostare_coordinate_cursore()
 * 	Descrizione: Questa funzione permette di impostare, tramite i codici ANSI, le coordinate del cursore nel terminale dove iniziare a stampare.
 * 	Parametri:
 * 		-x, y: coordinate nelle quali impostare il cursore sul terminale.
 */
void impostare_coordinate_cursore(int x, int y) {
	printf("\033[%d;%dH", y, x); //Il codice ANSI prevede di impostare prima la coordinata y e dopo la coordinata x.
	return;
}

/*	Funzione: mostare_cursore()
 * 	Descrizione: Questa funzione permette, tramite i codici ANSI, di mostare a video il cursore.
 */
void mostrare_cursore() {
	printf("\033[?25h");
	return;
}

/*	Funzione: nascondere_cursore()
 * 	Descrizione: Questa funzione permette, tramite i codici ANSI, di nascondere il cursore sul terminale.
 */
void nascondere_cursore() {
	printf("\033[?25l");
	return;
}

/*	Funzione: prendere_input_stringa_limitato()
 * 	Descrizione: Questa funzione permette di prendere in input una stringa da tastiera con un numero di caratteri limitato e stamparla a video.
 * 	Parametri:
 * 		-str, stringa da inserire
 * 		-dim_input, dimensione massima dell'input, ovvero quanti caratteri può inserire al massimo l'utente
 * 	 	-x, y: coordinate nelle quali stampare a video l'inserimento della stringa da parte dell'utente.
 *	Dato di ritorno:
 *		-str, stringa inserita dall'utente
 */
void prendere_input_stringa_limitato(stringa* str, int dim_input, int x, int y) {
	int i;
	int c;

	i = 0;
	c = 0;
	stringa_scrivere_dimensione(str, 0);
	while (c != TASTO_INVIO) {
		c = leggere_carattere();
		if (c != FRECCIA_SX &&
			c != FRECCIA_DX &&
			c != FRECCIA_SU &&
			c != FRECCIA_GIU
		) {
			if (c == TASTO_BACKSPACE && i > 0) {
				i = i - 1;
				stringa_scrivere_carattere(str, i, '\0');
			} else if (i < dim_input && c != TASTO_BACKSPACE && c != TASTO_INVIO) {
				stringa_scrivere_carattere(str, i, c);
				i = i + 1;
			}
			stringa_scrivere_dimensione(str, i);
			impostare_coordinate_cursore(x, y);
			printf("%*c", dim_input, ' ');
			impostare_coordinate_cursore(x, y);
			printf("%s", stringa_leggere_array(*str));
		}
	}

	stringa_scrivere_carattere(str, i, '\0');
	return;
}

/*	Funzione: pulire_schermo()
 * 	Descrizione: Questa funzione permette di pulire tutto ciò che era stampato sul terminale
 */
void pulire_schermo() {
	system("@cls||clear"); //cls è il comando da terminale per Windows, clear è il comando per Linux
	return;
}

/*	Funzione: stampare_banner_errore()
 * 	Descrizione: Questa funzione stampa il banner di errore qualora se ne verifichi uno.
 * 	Parametri:
 * 		-x, y: coordinate nelle quali iniziare a stampare il banner di errore
 * 		-messaggio_errore: array di caratteri contenente il messaggio di errore da stampare
 */
void stampare_banner_errore(int x, int y, int dim, char* messaggio_errore) {
	int i;				//Indice delle colonne del cursore
	i = 1;
	impostare_coordinate_cursore(x, y - 1);
	printf("+");
	while (i < dim - 2) {
		impostare_coordinate_cursore(x + i, y - 1);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(x + i, y - 1);
	printf("+");

	stampare_centrato_colorato(COLORE_ANSI_ROSSO, messaggio_errore, dim, y);

}

/*	Funzione: stampare_carattere_colorato()
 * 	Descrizione: Questa funzione permette di stampare, tramite codici ANSI, un carattere passato in input con un colore passato in input.
 * 	Parametri:
 * 		-colore: array di caratteri contentente il codice ANSI del colore
 * 		-c: carattere da stampare
 */
void stampare_carattere_colorato(char* colore, char c) {
	printf("%s%c%s", colore, c, COLORE_ANSI_RESET); //Dopo aver stampato il carattere colorato bisogna resettare il colore, sempre con codici ANSI
	return;
}

/*	Funzione: stampare_centrato_colorato()
 * 	Descrizione: Questa funzione permette di stampare un messaggio, con un dato colore, centrandolo rispetto alla dimensione del riquadro dato.
 * 	Parametri:
 * 		-colore: array di caratteri contentente il codice ANSI del colore
 * 		-stringa: array di caratteri contenente il messaggio da stampare
 * 		-dim_riquadro: dimensione del riquadro dove stampare il messaggio
 * 		-y: Riga del terminale dove stampare il riquadro
 */
void stampare_centrato_colorato(char* colore, char* stringa, int dim_riquadro, int y) {
	int n_spazi;			//Colonna, determinata con un calcolo, dove iniziare a stampre il messaggio
	n_spazi = (dim_riquadro - calcolare_lunghezza_stringa(stringa)) / 2 + 1;
	impostare_coordinate_cursore(n_spazi, y);
	printf("%s%s%s", colore, stringa, COLORE_ANSI_RESET); //Dopo aver stampato l'array di caratteri colorato, bisogna resettare il colore con codici ANSI.
}

/*	Funzione: stampare_colorato()
 * 	Descrizione: Questa funzione permette di stampare, tramite codici ANSI, un array di caratteri passato in input con un colore passato in input.
 * 	Parametri:
 * 		-colore: array di caratteri contentente il codice ANSI del colore
 * 		-stringa: array di caratteri da stampare
 */
void stampare_colorato(char* colore, char* stringa) {
	printf("%s%s%s", colore, stringa, COLORE_ANSI_RESET); //Dopo aver stampato l'array di caratteri colorato, bisogna resettare il colore con codici ANSI.
	return;
}

/*	Funzione: stampare_carattere_colorato_rgb()
 * 	Descrizione: Questa funzione permette di stampare, tramite codici ANSI, un carattere passato in input con un colore RGB passato in input.
 * 	Parametri:
 * 		-r: tonalità di rosso del colore RGB
 * 		-g: tonalità di verde del colore RGB
 * 		-b: tonalità di blu del colore RGB
 * 		-c: carattere da stampare
 */
void stampare_carattere_colorato_rgb(int r, int g, int b, char c) {
	printf("\x1b[38;2;%d;%d;%dm%c%s", r, g, b, c, COLORE_ANSI_RESET);
	//Dopo aver stampato l'array di caratteri colorato, bisogna resettare il colore con codici ANSI.
	return;
}

/*	Funzione: stampare_colorato_rgb()
 * 	Descrizione: Questa funzione permette di stampare, tramite codici ANSI, un array di caratteri passato in input con un colore RGB passato in input.
 * 	Parametri:
 * 		-r: tonalità di rosso del colore RGB
 * 		-g: tonalità di verde del colore RGB
 * 		-b: tonalità di blu del colore RGB
 * 		-stringa: array di caratteri da stampare
 */
void stampare_colorato_rgb(int r, int g, int b, char* stringa) {
	printf("\x1b[38;2;%d;%d;%dm%s%s", r, g, b, stringa, COLORE_ANSI_RESET);
	//Dopo aver stampato l'array di caratteri colorato, bisogna resettare il colore con codici ANSI.
	return;
}




