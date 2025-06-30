#include "gestire_menu_principale.h"

/*	Funzione: iniziare_partita()
 * 	Descrizione: Questa funzione gestisce la logica di selezione delle impostazioni prima di iniziare la partita.
 * 	Questa funzione gestisce 4 comandi principali:
 * 		-'1': Se l'utente seleziona 1 allora viene stampata l'interfaccia di selezione della difficolta' di gioco
 * 		-'2': Se l'utente seleziona 2 allora viene stampata l'interfaccia di selezione della dimensione della griglia
 * 		-'3': Se l'utente seleziona 3 l'utente può inserire il nome della partita
 * 		-'4': Se l'utente seleziona 4, si inizializza la griglia e la partita con le impostazioni selezionate e viene chiamata la funzione giocare_partita()
 * 	L'utente non può giocare la partita fino a quando non inserisce il nome della partita.
 * 	La selezione della difficoltà e della dimensione sono facoltativi in quanto se non vengono selezionate vengono assegnate difficoltà e dimensione standard.
 *  L'utente esce dall'interfaccia se preme '5' o se ha smesso di giocare la partita.
 * 	Parametri:
 * 		-partite_salvate: array di stringhe dei nomi delle partite salvate
 *	Dato di ritorno:
 *		-partite_salvate: array di stringhe dei nomi delle partite salvate aggiornato con l'eventuale nome della nuova partita avviata
 */
void iniziare_partita(stringa* partite_salvate) {
	bool_t uscito;							//Indica se l'utente ha smesso di giocare la partita
	char comando_utente;
	int difficolta_scelta;					//Difficoltà di gioco scelta dall'utente
	int dim_griglia_scelta;					//Dimensione della griglia scelta dall'utente
	stringa nome_partita;					//Nome della partita scelta dall'utente
	griglia griglia_sudoku;					//Griglia di gioco della partita
	impostazioni impostazioni_gioco;		//Impostazioni di gioco della partita scelte dall'utente
	partita partita_da_giocare;				//Partita inizializzata con le impostazioni e il nome della partita selezionati
	bool_t nome_impostato;					//Indica se il nome della partita è stato impostato o meno
	bool_t nome_vuoto;						//Indica se è stato inserito un nome di partita vuoto
	bool_t nome_errato;						//Indica se è stato inserito un nome di partita con caratteri non ammessi

	nome_errato = FALSO;
	nome_impostato = FALSO;
	nome_vuoto = FALSO;
	uscito = FALSO;
	difficolta_scelta = DIFFICOLTA_STANDARD;
	dim_griglia_scelta = DIM_GRIGLIA_STANDARD;
	stringa_scrivere_dimensione(&nome_partita, 0);

	do {
		stampare_interfaccia_impostazioni();
		//Se il nome della partita è vuoto, contiene caratteri non ammessi o non è stato impostato allora viene stampato un banner di errore
		if (nome_impostato == FALSO && nome_vuoto == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_NOME_FILE_VUOTO);
		} else if (nome_impostato == FALSO && nome_errato == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_NOME_FILE_ERRATO);
		} else if (nome_impostato == FALSO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_NOME_FILE);
		}
		nome_errato = FALSO;
		nome_vuoto = FALSO;
		comando_utente = nascondere_input_utente();
		if(comando_utente == '1') {
			difficolta_scelta = selezionare_difficolta(difficolta_scelta);
		}
		if(comando_utente == '2') {
			dim_griglia_scelta = selezionare_dimensione_griglia(dim_griglia_scelta);
		}
		if(comando_utente == '3') {
			impostare_coordinate_cursore(56, 12);
			printf(": ");
			mostrare_cursore();
			prendere_input_stringa_limitato(&nome_partita, DIM_MAX_STRINGA - strlen(ESTENSIONE_FILE), 58, 12);
			//Controlliamo se il nome inserito contiene caratteri non ammessi oppure ha una dimensione pari a 0, cioè costituito dal solo carattere \n.
			if (controllare_caratteri_stringa(nome_partita, CARATTERI_NOME_FILE_NON_AMMESSI) == FALSO) {
				nome_impostato = FALSO;
				nome_errato = VERO;
			} else if (stringa_leggere_dimensione(nome_partita) <= 0) {
				nome_impostato = FALSO;
				nome_vuoto = VERO;
			} else {
				nome_impostato = VERO;
			}

		}
		//Se il nome della partita è stato impostato, vengono inizializzate le impostazioni con dimensione e difficoltà scelte.
		//Viene inizializzata la griglia secondo le impostazioni scelte e viene inizializzata la partita secondo le impostazioni, la griglia e il nome scelto.
		if(comando_utente == '4' && nome_impostato == VERO) {
			impostare_parametri_di_gioco(&impostazioni_gioco, difficolta_scelta, dim_griglia_scelta);
			inizializzare_griglia(&griglia_sudoku, impostazioni_gioco);
			inizializzare_partita(impostazioni_gioco, griglia_sudoku, nome_partita, &partita_da_giocare);
			partite_salvate = giocare_partita(partita_da_giocare);
			uscito = VERO; //Se l'utente finisce di giocare deve tornare al menu principale
		}
	} while(comando_utente != '5' && !uscito);
	return;
}

/*	Funzione: menu_principale()
 * 	Descrizione: Questa funzione permette di gestire la logica del menu principale.
 * 	Nel menu principale, l'utente può scegliere se iniziare una nuova partita, oppure caricarne una già esistente.
 * 	Parametri:
 * 		-partite_salvate: array di stringhe dei nomi delle partite salvate.
 *	Dato di ritorno:
 *		-partite_salvate: array di stringhe dei nomi delle partite salvate aggiornato.
 */
void menu_principale(stringa* partite_salvate) {
	char comando_utente;
	partita partita_caricata;	//Partita da caricare
	bool_t caricato;			//Indica se la partita è stata caricata correttamente
	do {
		stampare_interfaccia_menu_principale();
		comando_utente = nascondere_input_utente();
		if (comando_utente == '1') {
			iniziare_partita(partite_salvate);
		}
		if (comando_utente == '2') {
			caricato = caricare_partita(&partita_caricata);
			if (caricato == VERO) {
				partite_salvate = giocare_partita(partita_caricata);
			}
		}
	} while(comando_utente != '3');
	return;
}


/*	Funzione: stampare_interfaccia_menu_principale()
 * 	Descrizione: Questa funzione stampa il menu principale di gioco.
 */
void stampare_interfaccia_menu_principale() {
	int voci_menu_x;			//Colonna nella quale stampare le voci del menu
	int inizio_voci_menu_y;		//Inizio di riga nella quale stampare le voci del menu
	voci_menu_x = 32;
	inizio_voci_menu_y = 12;
	pulire_schermo();
	disegnare_riquadro_interfaccia();

	//Stampiamo all'inizio della finestra la scritta | SUDOKU | centrandola rispetto alla larghezza della finestra
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| SUDOKU |", LARGHEZZA_FINESTRA, 1);
	//Stampiamo alla riga successiva la scritta +--------+ centrandola rispetto alla larghezza della finestra
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+--------+", LARGHEZZA_FINESTRA, 2);
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y);
	printf("1. Inizia partita");
	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 1);
 	printf("2. Carica partita");
 	impostare_coordinate_cursore(voci_menu_x, inizio_voci_menu_y + 2);
	printf("3. Esci");
}
