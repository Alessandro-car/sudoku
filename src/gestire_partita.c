#include "gestire_partita.h"
#include "math.h"
//TODO: Lo pseudo va modificato
//Funzione che inserisce un valore nella griglia del sudoku dopo averne controllato la correttezza
void aggiornare_griglia(griglia* griglia, int valore, int riga, int colonna){
	valore_griglia val;
	if (validare_input_utente(riga, colonna, convertire_numeri_in_lettere(valore), *griglia) == VERO){
		valore_griglia_scrivere_valore(&val, valore);
		valore_griglia_scrivere_modificabile(&val, VERO);
		griglia_scrivere_valore(griglia, riga - 1, colonna - 1, val);
	}
	return;
}

bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco){
	bool_t validato;
	int dim_griglia;
	validato = FALSO;
	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	valore = convertire_minuscolo_maiuscolo(valore);

	if (validare_riga_input(riga, dim_griglia) == VERO &&
		validare_colonna_input(colonna, dim_griglia) == VERO &&
		validare_valore_input(valore, dim_griglia) == VERO &&
		valore_griglia_leggere_modificabile(griglia_leggere_valore(griglia_gioco, riga - 1, colonna - 1)) == VERO) {
		validato = VERO;
	}

	return validato;
}

bool_t verificare_coordinate_e_valore(griglia griglia_gioco, int coordinata_x, int coordinata_y, int valore) {
	bool_t valido;
	valido = VERO;

	if (valore_griglia_leggere_valore(griglia_leggere_valore(griglia_gioco, coordinata_x, coordinata_y)) != 0) {
		valido = FALSO;
	}
	return valido;
}

//TODO: cambiare pseudo
//Funzione che esegue un controllo sulla colonna inserita in input dall'utente, essa verifica se è valida o meno.
bool_t validare_colonna_input(int colonna, int dim_griglia) {
	bool_t validato;       //Indica se la colonna è valida o meno

	validato = VERO;
  if(colonna <= 0 || colonna > dim_griglia){
  	validato = FALSO;
  }
  return validato;
}

//Funzione che esegue un controllo sulla colonna inserita e verifica se il numero da inserire è gia presente o meno
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


//TODO: modificare lo pseudo
//La seguente funzione permette di verificare se un valore inserito dall'utente può venir considerato valido
bool_t validare_valore_input(char valore, int dim_griglia) {
	int validato;
	int dim_griglia_carattere;

	validato = VERO;
	dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

	if(dim_griglia > DIM_GRIGLIA_GRANDE) {
		validato = FALSO;
	} else {
		if(dim_griglia <= DIM_GRIGLIA_GRANDE && (valore <= CHAR_0 || (valore > CHAR_9 && valore < CHAR_A) || valore > dim_griglia_carattere))  {
			validato = FALSO;
		}
	}
	return validato;
}

//La seguente funzione permette di verificare se è stato inserito un numero in una "cella" non valida, effettuando controlli su riga, colonna e regione
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
	/*if(corretto == VERO) {//Se il primo controllo è andato a buon fine allora passa al controllo della colonna
		corretto = controllare_colonna(griglia, colonna, numero_da_inserire, dimensione_griglia); //Imposta corretto con la funzione controllare_colonna che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa colonna
	}
	if(corretto == VERO) {//Se il secondo controllo è andato a buon fine passa al controllo sulla regione
		riga = riga - calcolare_resto_intero(riga, dimensione_regione);//Permette di ottenere la dimensione della riga della regione
		colonna =  colonna - calcolare_resto_intero(colonna, dimensione_regione); //Permette di ottenere la dimensione della colonna della regione
		corretto = controllare_regione(griglia, riga, colonna, numero_da_inserire, dimensione_regione);//Imposta corretto con la funzione controllare_regione che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa regione
	}*/
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

//TODO: cambiare lo pseudo
bool_t validare_riga_input(int riga, int dim_griglia) {
	bool_t validato;
	validato = VERO;
	if (riga <= 0 || riga > dim_griglia) {
		validato = FALSO;
	}
	return validato;
}

// Verifica che il numero non sia già presente nella riga specificata
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

stringa* giocare_partita(partita partita_corrente) {
	stringa* partite_salvate;
	griglia griglia_gioco;
	char comando_utente;
	char riga;
	char colonna;
	char valore;
	partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));
	do {
		stampare_schermata_di_gioco(partita_corrente);
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
			aggiornare_griglia(&griglia_gioco, convertire_lettera_in_numero(valore), convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna));
			partita_scrivere_griglia(&partita_corrente, griglia_gioco);
		}
	} while (comando_utente != TASTO_ESC);

	return partite_salvate;
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
	i = 0;
	while(i < griglia_leggere_dimensione(griglia_gioco)) {
		j = 0;
		impostare_coordinate_cursore(4, 3 + i);
		printf("|");
		while(j < griglia_leggere_dimensione(griglia_gioco)) {
			val = griglia_leggere_valore(griglia_gioco, i, j);
			val_carattere = convertire_numeri_in_lettere(valore_griglia_leggere_valore(val));
			if (val_carattere == '0') {
				printf(" |");
			} else {
				if (valore_griglia_leggere_modificabile(val) == FALSO) {
					stampare_carattere_colorato(COLORE_ANSI_CIANO, val_carattere);
					printf("|");
				} else {
					printf("%c|", val_carattere);
				}
			}
			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}
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
	while(i < 25) {
		impostare_coordinate_cursore(50, i);
		printf("|");
		i = i + 1;
	}

	impostare_coordinate_cursore(52, 2);
	printf("Input:");
	impostare_coordinate_cursore(52, 4);
	printf("Riga:");
	impostare_coordinate_cursore(52, 5);
	printf("Colonna:");
	impostare_coordinate_cursore(52, 6);
	printf("Valore:");

	i = 0;
	while (i < 28) {
		impostare_coordinate_cursore(51 + i, 8);
		printf("-");
		i = i + 1;
	}
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

	i = 0;
	while (i < 28) {
		impostare_coordinate_cursore(51 + i, 15);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(52, 16);
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
	impostare_coordinate_cursore(52, 17);
	printf("Difficolta': %s", mess_difficolta);
	impostare_coordinate_cursore(52, 18);
	printf("Dimensione: %dx%d", dim_griglia, dim_griglia);
	impostare_coordinate_cursore(52, 19);
	printf("Nome: %s", stringa_leggere_array(partita_leggere_nome(partita_corrente)));
}
