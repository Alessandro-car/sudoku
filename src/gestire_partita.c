#include "gestire_partita.h"

void giocare_partita(partita partita_corrente) {
	griglia griglia_gioco;
	char comando_utente;
	char riga;
	char colonna;
	char valore;
	bool_t valore_modificabile;
	bool_t input_corretto;

	valore_modificabile = VERO;
	input_corretto = VERO;
	do {

		stampare_schermata_di_gioco(partita_corrente);
		if (valore_modificabile == FALSO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1, ERRORE_VALORE_NON_MODIFICABILE);
		} else if (input_corretto == FALSO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 1, ERRORE_INPUT_ERRATI);
		}
		valore_modificabile = VERO;
		input_corretto = VERO;
		comando_utente = nascondere_input_utente();
		comando_utente = convertire_minuscolo_maiuscolo(comando_utente);

		// Gestisce il comando di salvataggio della partita
		if (comando_utente == 'S') {
			salvare_partita(partita_corrente);
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

			input_corretto = validare_input_utente(convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna), valore, griglia_gioco);
			if (input_corretto == VERO) {
				valore_modificabile = valore_griglia_leggere_modificabile(griglia_leggere_valore(griglia_gioco, convertire_lettera_in_numero(riga) - 1, convertire_lettera_in_numero(colonna) - 1));
			}

			if (valore_modificabile == VERO && input_corretto == VERO) {
				aggiornare_griglia(&griglia_gioco, convertire_lettera_in_numero(valore), convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna));
				partita_scrivere_griglia(&partita_corrente, griglia_gioco);
			}
		}
	} while (comando_utente != TASTO_ESC);

	return;
}

void stampare_informazioni_utente(partita partita_corrente) {
	int i;
	char val_min;
	char val_max;
	int dim_griglia;
	int difficolta;
	char* mess_difficolta;
	int pos_x_input;
	int pos_y_input;
	pos_x_input = SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X + 2;
	pos_y_input = 2;
	dim_griglia = impostazioni_leggere_dimensione_griglia(partita_leggere_impostazioni(partita_corrente));
	difficolta = impostazioni_leggere_difficolta(partita_leggere_impostazioni(partita_corrente));
	i = 2;
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, i - 1);
	printf("+");
	while(i < LUNGHEZZA_FINESTRA) {
		impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, i);
		printf("|");
		i = i + 1;
	}

	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, i);
	printf("+");

	impostare_coordinate_cursore(pos_x_input, pos_y_input);
	printf("Input:");
	impostare_coordinate_cursore(pos_x_input, pos_y_input + 2);
	printf("Riga:");
	impostare_coordinate_cursore(pos_x_input, pos_y_input + 3);
	printf("Colonna:");
	impostare_coordinate_cursore(pos_x_input, pos_y_input + 4);
	printf("Valore:");

	i = 0;
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, 8);
	printf("+");
	while (i < 28) {
		impostare_coordinate_cursore(51 + i, 8);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(51 + i, 8);
	printf("+");

	impostare_coordinate_cursore(52, 9);
	printf("Comandi:");
	impostare_coordinate_cursore(52, 10);
	printf("S: Salva");
	impostare_coordinate_cursore(52, 11);
	printf("I: Input");
	impostare_coordinate_cursore(52, 12);
	printf("ESC: Tornare al menu");
	val_min = '1';
	val_max = convertire_numeri_in_lettere(dim_griglia);
	impostare_coordinate_cursore(52, 13);
	printf("%c-%c: Range input", val_min, val_max);
	impostare_coordinate_cursore(52, 14);
	printf("0: Cancellare valore");

	i = 0;
	impostare_coordinate_cursore(SPAZIO_RISERVATO_GRIGLIA_INTERFACCIA_X, 15);
	printf("+");
	while (i < 28) {
		impostare_coordinate_cursore(51 + i, 15);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(51 + i, 15);
	printf("+");

	impostare_coordinate_cursore(52, 17);
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
	impostare_coordinate_cursore(52, 18);
	printf("Difficolta': %s", mess_difficolta);
	impostare_coordinate_cursore(52, 19);
	printf("Dimensione: %dx%d", dim_griglia, dim_griglia);
	impostare_coordinate_cursore(52, 20);
	printf("Nome: %s", stringa_leggere_array(partita_leggere_nome(partita_corrente)));
	free(mess_difficolta);
	return;
}

void stampare_schermata_di_gioco(partita partita_corrente) {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_griglia(partita_leggere_griglia(partita_corrente));
	stampare_informazioni_utente(partita_corrente);
}
