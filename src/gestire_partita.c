#include "gestire_partita.h"

/*	Funzione: giocare_partita()
 * 	Descrizione: Questa funzione gestisce la logica di gioco della partita.
 * 	Questa funzione stampa l'interfaccia della schermata di gioco e gestisce due comandi fondamentali:
 * 		-'S': al suo inserimento, viene stampata l'interfaccia per salvare la partita
 * 		-'I': al suo inserimento l'utente può inserire un valore nella griglia di gioco indicandone le coordinate
 * 	Per smettere di giocare l'utente dovrà premere ESC.
 * 	Parametri:
 * 		-partita_corrente: partita creata con le impostazioni selezionate dall'utente o caricata da un file.
 *	Dato di ritorno:
 *		-partite_salvate: array di stringhe dei nomi delle partite salvate.
 */
stringa* giocare_partita(partita partita_corrente) {
	stringa* partite_salvate;			//Array di stringhe dei nomi delle partite salvate
	griglia griglia_gioco;				//Griglia di gioco della partita corrente
	char comando_utente;
	char riga;							//Riga della griglia nella quale inserire il valore
	char colonna;						//Colonna della griglia nella quale inserire il valore
	char valore;						//Valore da inserire nella griglia nelle coordinate date
	bool_t valore_modificabile;			//Indica se il valore della griglia nelle coordinate date è modificabile o meno
	bool_t input_corretto;				//Indica se sono stati inseriti degli input corretti
	partite_salvate = calloc(MAX_PARTITE_SALVATE, sizeof(stringa));
	valore_modificabile = VERO;
	input_corretto = VERO;
	do {

		stampare_schermata_di_gioco(partita_corrente);
		//Se si prova a modificare un valore non modificabile viene stampato un banner di errore
		//Se si inserisce un input non corretto viene stampato un banner di errore
		if (valore_modificabile == FALSO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1, ERRORE_VALORE_NON_MODIFICABILE);
		}
		else if (input_corretto == FALSO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1, ERRORE_INPUT_ERRATI);
		}
		valore_modificabile = VERO;
		input_corretto = VERO;
		comando_utente = nascondere_input_utente();
		comando_utente = convertire_minuscolo_maiuscolo(comando_utente);

		if (comando_utente == 'S') {
			partite_salvate = salvare_partita(partita_corrente);
		}

		if (comando_utente == 'I') {
			impostare_coordinate_cursore(58, 4);
			mostrare_cursore();
			riga = prendere_input_carattere_limitato(58, 4);
			impostare_coordinate_cursore(61, 5);
			colonna = prendere_input_carattere_limitato(61, 5);
			impostare_coordinate_cursore(60, 6);
			valore = prendere_input_carattere_limitato(60, 6);
			riga = convertire_minuscolo_maiuscolo(riga);
			colonna = convertire_minuscolo_maiuscolo(colonna);
			valore = convertire_minuscolo_maiuscolo(valore);

			griglia_gioco = partita_leggere_griglia(partita_corrente);
			//Controlla se le coordinate e il valore inseriti sono corretti.
			input_corretto = validare_input_utente(convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna), valore, griglia_gioco);
			//Se l'input è corretto, controlla se il valore della griglia in quelle coordinate può essere modificato o meno
			if (input_corretto == VERO) {
				valore_modificabile = valore_griglia_leggere_modificabile(griglia_leggere_valore(griglia_gioco, convertire_lettera_in_numero(riga) - 1, convertire_lettera_in_numero(colonna) - 1));
			}
			//Se il valore può essere modificato e l'input è corretto allora viene inserito il valore nella griglia e viene aggiornata la griglia
			if (valore_modificabile == VERO && input_corretto == VERO) {
				aggiornare_griglia(&griglia_gioco, convertire_lettera_in_numero(valore), convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna));
				partita_scrivere_griglia(&partita_corrente, griglia_gioco);
			}
		}
	} while (comando_utente != TASTO_ESC);

	return partite_salvate;
}

/*	Funzione: stampare_informazioni_utente()
 * 	Descrizione: Questa funzione stampa una parte di interfaccia della schermata di gioco,
 * 	riservata all'area di Input, dei comandi e di informazioni della partita.
 */
void stampare_informazioni_utente(partita partita_corrente) {
	int i;						//Indice della colonna del cursore
	char val_min;				//Valore minimo inseribile nella griglia
	char val_max;				//Valore massimo inseribile nella griglia
	int dim_griglia;			//Dimensione della griglia
	int difficolta;				//Livello numerico di difficoltà
	char* mess_difficolta;		//Livello di difficoltà convertito in array di caratteri
	int pos_x_input;			//Colonna nella quale stampare l'area di Input
	int pos_y_input;			//Riga nella quale stampare l'area di Input
	pos_x_input = SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2;
	pos_y_input = 2;
	dim_griglia = impostazioni_leggere_dimensione_griglia(partita_leggere_impostazioni(partita_corrente));
	difficolta = impostazioni_leggere_difficolta(partita_leggere_impostazioni(partita_corrente));
	i = 2;
	//Stampiamo i separatori tra la griglia di gioco e l'area riservata alle informazioni della partita
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, i - 1);
	printf("+");
	while(i < LUNGHEZZA_FINESTRA) {
		impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, i);
		printf("|");
		i = i + 1;
	}

	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, i);
	printf("+");

	//Stampiamo i messaggi riservati all'area di Input
	impostare_coordinate_cursore(pos_x_input, pos_y_input);
	printf("Input:");
	//Spazio riservato all'input della riga
	impostare_coordinate_cursore(pos_x_input, pos_y_input + 2);
	printf("Riga:");
	//Spazio riservato all'input della colonna
	impostare_coordinate_cursore(pos_x_input, pos_y_input + 3);
	printf("Colonna:");
	//Spazio riservato all'input del valore
	impostare_coordinate_cursore(pos_x_input, pos_y_input + 4);
	printf("Valore:");

	i = 0;
	//Separiamo l'area di Input dall'area riservata ai comandi
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, 8);
	printf("+");
	while (i < LARGHEZZA_FINESTRA - SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X - 2) {
		impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1 + i, 8);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1 + i, 8);
	printf("+");

	//Stampiamo i messaggi riservata all'area dei comandi
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 9);
	printf("Comandi:");
	//Messagio del comando per salvare
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 10);
	printf("S: Salva");
	//Messaggio del comando per passare all'area di input
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 11);
	printf("I: Input");
	//Messaggio per uscire dalla partita
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 12);
	printf("ESC: Tornare al menu");
	val_min = '1';
	val_max = convertire_numeri_in_lettere(dim_griglia);
	//Messaggio dei range dei valori accettabili per gli input
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 13);
	printf("%c-%c: Range input", val_min, val_max);
	//Messaggio di cancellazione di un valore della griglia inserendone le coordinate
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 14);
	printf("Cancellazione valore:");
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 4, 15);
	printf("1. I: Input");
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 4, 16);
	printf("2. Inserire coordinate");
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 4, 17);
	printf("3. 0 al valore");


	//Separiamo l'area riservata ai comandi dall'area riservata alla informazioni della partita
	i = 0;
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, 18);
	printf("+");
	while (i < LARGHEZZA_FINESTRA - SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X - 2) {
		impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1 + i, 18);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1 + i, 18);
	printf("+");

	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 19);
	printf("Informazioni partita");
	if (difficolta == DIFFICOLTA_STANDARD) {
		mess_difficolta = "Facile";
	} else if (difficolta == DIFFICOLTA_MEDIA) {
		mess_difficolta = "Media";
	} else if (difficolta == DIFFICOLTA_DIFFICILE) {
		mess_difficolta = "Difficile";
	} else {
		mess_difficolta = "";
	}
	//Messaggio della difficoltà di gioco
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 20);
	printf("Difficolta': %s", mess_difficolta);
	//Messaggio della dimensione della griglia di gioco
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 21);
	printf("Dimensione: %dx%d", dim_griglia, dim_griglia);
	//Messaggio del nome della partita
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2, 22);
	printf("Nome: %s", stringa_leggere_array(partita_leggere_nome(partita_corrente)));
	free(mess_difficolta);
	return;
}

/*	Funzione: stampare_schermata_di_gioco()
 * 	Descrizione: Questa funzione stampa la schermata di gioco,
 * 	richiamando le funzioni di stampa della griglia e della parte riservata alle informazioni della partita
 */
void stampare_schermata_di_gioco(partita partita_corrente) {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_griglia(partita_leggere_griglia(partita_corrente));
	stampare_informazioni_utente(partita_corrente);
}
