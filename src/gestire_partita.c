#include "gestire_partita.h"

bool_t controllare_colonna(griglia griglia, int colonna, int numeri_da_inserire, int dimensione_griglia) {
  bool_t corretto;           //Indica se il numero può essere inserito o meno
  int i;
  int valore_cella;
  corretto = VERO;
  i = 0;
  while(i < dimensione_griglia){
	  valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, colonna));
      if(valore_cella == numeri_da_inserire){
      	corretto = FALSO;
      }
      i = i + 1;
  }
	return corretto;
}

bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione) {
	bool_t corretto;
	int i;
	int j;
	int valore_cella;

	corretto = VERO;
	i = riga;
	while (i < riga + dimensione_regione) {
		j = colonna;
		while (j < colonna + dimensione_regione) {
			valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, j));
			if (valore_cella == numero_da_inserire) {
				corretto = FALSO;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return corretto;
}

bool_t controllare_riga(griglia sudoku, int riga, int numero_da_inserire, int dimensione_sudoku) {
	bool_t corretto;
	int j;
	int valore_cella;

	corretto = VERO;
	j = 0;
	while (j < dimensione_sudoku) {
		valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(sudoku, riga, j));
		// Se il valore nella cella corrente è uguale al numero che vogliamo inserire,
		// allora il numero non può essere inserito in questa riga
		if (valore_cella == numero_da_inserire) {
				corretto = FALSO;
		}
		j = j + 1;
	}
	return corretto;
}

bool_t validare_colonna_input(int colonna, int dim_griglia) {
	bool_t validato;       //Indica se la colonna è valida o meno

	validato = VERO;
  if(colonna <= 0 || colonna > dim_griglia){
  	validato = FALSO;
  }
  return validato;
}

bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco){
	bool_t validato;
	int dim_griglia;
	validato = FALSO;
	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	valore = convertire_minuscolo_maiuscolo(valore);

	if (validare_riga_input(riga, dim_griglia) == VERO &&
		validare_colonna_input(colonna, dim_griglia) == VERO &&
		validare_valore_input(valore, dim_griglia) == VERO) {
		validato = VERO;
	}

	return validato;
}

bool_t validare_riga_input(int riga, int dim_griglia) {
	bool_t validato;
	validato = VERO;
	if (riga <= 0 || riga > dim_griglia) {
		validato = FALSO;
	}
	return validato;
}

bool_t validare_valore_input(char valore, int dim_griglia) {
	int validato;
	int dim_griglia_carattere;

	validato = VERO;
	dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

	if(dim_griglia > DIM_GRIGLIA_GRANDE) {
		validato = FALSO;
	} else {
		if(dim_griglia <= DIM_GRIGLIA_GRANDE && (valore < CHAR_0 || (valore > CHAR_9 && valore < CHAR_A) || valore > dim_griglia_carattere))  {
			validato = FALSO;
		}
	}
	return validato;
}

bool_t verificare_coordinate_e_valore(griglia griglia_gioco, int coordinata_x, int coordinata_y) {
	bool_t valido;
	valido = VERO;

	if (valore_griglia_leggere_valore(griglia_leggere_valore(griglia_gioco, coordinata_x, coordinata_y)) != 0) {
		valido = FALSO;
	}
	return valido;
}

bool_t verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna) {
	bool_t corretto; //Sarà l'output della funzione ed è un booleano, permette di capire se il numero è già presente in riga, colonna, regione o meno
	int dimensione_griglia;//La seguente variabile verrà inizializzata con la dimensione della griglia
	int dimensione_regione;//Viene inizializzata con la dimensione della regione della griglia

	dimensione_griglia = griglia_leggere_dimensione(griglia);
	dimensione_regione = calcolare_radice_quadrata(dimensione_griglia);//La funzione calcolare_radice_quadrata permette di ottenere la dimensione esatta della regione
	//corretto = controllare_riga(griglia, riga, numero_da_inserire, dimensione_griglia); //Inizializza corretto con la funzione controllare_riga che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa riga
	corretto = FALSO;
	int inizio_regione_R = riga - calcolare_resto_intero(riga, dimensione_regione);
	int inizio_regione_C = colonna - calcolare_resto_intero(colonna, dimensione_regione);
	if (
		controllare_riga(griglia, riga, numero_da_inserire, dimensione_griglia ) == VERO   &&
		controllare_colonna(griglia, colonna, numero_da_inserire, dimensione_griglia) == VERO &&
		controllare_regione(griglia, inizio_regione_R, inizio_regione_C, numero_da_inserire, dimensione_regione) == VERO
		) {
		corretto = VERO;
	}
	return corretto;
}

void aggiornare_griglia(griglia* griglia, int valore, int riga, int colonna){
	valore_griglia val;
	valore_griglia_scrivere_valore(&val, valore);
	valore_griglia_scrivere_modificabile(&val, VERO);
	griglia_scrivere_valore(griglia, riga - 1, colonna - 1, val);
	return;
}

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
			stampare_banner_errore(1, 24, 51, ERRORE_VALORE_NON_MODIFICABILE);
		} else if (input_corretto == FALSO) {
			stampare_banner_errore(1, 24, 51, ERRORE_INPUT_ERRATI);
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
	dim_griglia = impostazioni_leggere_dimensione_griglia(partita_leggere_impostazioni(partita_corrente));
	difficolta = impostazioni_leggere_difficolta(partita_leggere_impostazioni(partita_corrente));
	i = 2;
	impostare_coordinate_cursore(50, i - 1);
	printf("+");
	while(i < 25) {
		impostare_coordinate_cursore(50, i);
		printf("|");
		i = i + 1;
	}

	impostare_coordinate_cursore(50, i);
	printf("+");

	impostare_coordinate_cursore(52, 2);
	printf("Input:");
	impostare_coordinate_cursore(52, 4);
	printf("Riga:");
	impostare_coordinate_cursore(52, 5);
	printf("Colonna:");
	impostare_coordinate_cursore(52, 6);
	printf("Valore:");

	i = 0;
	impostare_coordinate_cursore(50, 8);
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
	impostare_coordinate_cursore(50, 15);
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

void stampare_interfaccia_impostazioni(void) {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	impostare_coordinate_cursore(33, 1);
	printf("| IMPOSTAZIONI |");
	impostare_coordinate_cursore(33, 2);
	printf("+--------------+");
	impostare_coordinate_cursore(31, 10);
 	printf("1. Scegli difficolta'");
 	impostare_coordinate_cursore(31, 11);
 	printf("2. Scegli dimensione");
 	impostare_coordinate_cursore(31, 12);
 	printf("3. Inserisci nome partita");
 	impostare_coordinate_cursore(31, 13);
 	printf("4. Prosegui");
 	impostare_coordinate_cursore(31, 14);
 	printf("5. Torna indietro");
	return;
}

void stampare_schermata_di_gioco(partita partita_corrente) {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_griglia(partita_leggere_griglia(partita_corrente));
	stampare_informazioni_utente(partita_corrente);
}

void stampare_griglia(griglia griglia_gioco) {
	int i;
	int j;
	valore_griglia val;
	char val_carattere;
	int dim_griglia;
	int dim_regione;
	int row;
	int n_regioni;

	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	dim_regione = calcolare_radice_quadrata(dim_griglia);
	i = 0;
	while (i < dim_griglia + dim_regione - 1) {
		j = 0;
		while (j <= dim_griglia * 2) {
			impostare_coordinate_cursore(4 + j, 3 + i);
			if (calcolare_resto_intero(j, dim_regione * 2) == 0) {
				stampare_carattere_colorato(COLORE_ANSI_CIANO, '|');
			} else {
				printf("|");
			}
			j = j + 2;
		}
		i = i + 1;
	}

	i = dim_regione;
	while(i < dim_griglia) {
		j = 0;
		while (j <= dim_griglia * 2) {
			impostare_coordinate_cursore(4 + j, 3 + i);
			if (calcolare_resto_intero(j, dim_regione * 2) == 0) {
				stampare_carattere_colorato(COLORE_ANSI_CIANO, '+');
			}
			else if (calcolare_resto_intero(j, dim_regione / 2) == 0) {
				printf("+");
			}else {
				printf("-");
			}
			j = j + 1;
		}
		i = i + dim_regione + 1;
	}

	i = 0;
	row = 0;
	n_regioni = 0;
	while (i <= dim_griglia + dim_regione - 1 && row < dim_griglia) {
	j = 0;
	if (calcolare_resto_intero(i, dim_regione) == 0 && i != 0) {
		n_regioni = n_regioni + 1;
	}
	while(j < dim_griglia) {
			impostare_coordinate_cursore(5 + (j * 2), 3 + i + n_regioni);
			val = griglia_leggere_valore(griglia_gioco, row, j);
			val_carattere = convertire_numeri_in_lettere(valore_griglia_leggere_valore(val));
			if (val_carattere == '0') {
				printf(" ");
			} else {
				if (valore_griglia_leggere_modificabile(val) == FALSO) {
					stampare_carattere_colorato(COLORE_ANSI_ROSSO, val_carattere);
				} else {
					printf("%c", val_carattere);
				}
			}
			j = j + 1;
		}
		row = row + 1;
		i = i + 1;
	}

	return;
}
