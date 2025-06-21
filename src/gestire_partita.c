#include "gestire_partita.h"
//TODO: Lo pseudo va modificato
//Funzione che inserisce un valore nella griglia del sudoku dopo averne controllato la correttezza
void aggiornare_griglia (griglia* griglia, int valore, int riga, int colonna){
	if (validare_input_utente(riga, colonna, convertire_numeri_in_lettere(valore), *griglia) == VERO){
		griglia_scrivere_valore(griglia, riga - 1, colonna - 1, valore);
	}
	return;
}

bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco){
	bool_t validato;
	int dim_griglia;
	validato = FALSO;
	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	valore = convertire_minuscolo_maiuscolo(valore);

	if (validare_riga_input(riga, dim_griglia) == VERO && validare_colonna_input(colonna, dim_griglia) == VERO && validare_valore_input(valore, dim_griglia) == VERO) {
		validato = VERO;
	}

	return validato;
}

bool_t verificare_coordinate_e_valore(griglia griglia_gioco, int coordinata_x, int coordinata_y, int valore) {
	bool_t valido;
	valido = VERO;

	if (griglia_leggere_valore(griglia_gioco, coordinata_x, coordinata_y) != 0) {
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
  corretto = VERO;
  i = 1;
  while(i < dimensione_griglia){
      if(griglia_leggere_valore(griglia, i, colonna) == numeri_da_inserire){
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

	int corretto; //Sarà l'output della funzione ed è un booleano, permette di capire se il numero è già presente in riga, colonna, regione o meno
	int dimensione_griglia;//La seguente variabile verrà inizializzata con la dimensione della griglia
	int dimensione_regione;//Viene inizializzata con la dimensione della regione della griglia

	dimensione_griglia = griglia_leggere_dimensione(griglia);
	dimensione_regione = calcolare_radice_quadrata(dimensione_griglia);//La funzione calcolare_radice_quadrata permette di ottenere la dimensione esatta della regione
	corretto = controllare_riga(griglia, riga, numero_da_inserire, dimensione_griglia); //Inizializza corretto con la funzione controllare_riga che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa riga
	if(corretto == VERO) {//Se il primo controllo è andato a buon fine allora passa al controllo della colonna
		corretto = controllare_colonna(griglia, colonna, numero_da_inserire, dimensione_griglia); //Imposta corretto con la funzione controllare_colonna che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa colonna
	}
	if(corretto == VERO) {//Se il secondo controllo è andato a buon fine passa al controllo sulla regione
		riga = riga - calcolare_resto_intero(riga, dimensione_regione);//Permette di ottenere la dimensione della riga della regione
		colonna =  colonna - calcolare_resto_intero(colonna, dimensione_regione); //Permette di ottenere la dimensione della colonna della regione
		corretto = controllare_regione(griglia, riga, colonna, numero_da_inserire, dimensione_regione);//Imposta corretto con la funzione controllare_regione che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa regione
	}
	return corretto;
}

bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione) {
	bool_t corretto;
	int i;

	corretto = VERO;
	i = riga;
	while (i < riga + dimensione_regione) {
		int j;
		j = colonna;
		while ( j < colonna + dimensione_regione ) {
			if (griglia_leggere_valore(griglia, i, j) == numero_da_inserire) {
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

//Funzione che si occupa di salvare la partita su file.
void salvare_partita(FILE* file_salvataggio, partita partita_da_salvare) {
	fwrite(&partita_da_salvare, sizeof(partita), 1, file_salvataggio);
	fclose(file_salvataggio);
	return;
}

// Verifica che il numero non sia già presente nella riga specificata
bool_t controllare_riga(griglia sudoku, int riga, int numero_da_inserire, int dimensione_sudoku) {
	bool_t corretto;
	int j;
	int valore_cella;

	corretto = VERO;
	j = 0;
	while (j < dimensione_sudoku && corretto == VERO) {
		valore_cella = griglia_leggere_valore(sudoku, riga, j);
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
	impostare_coordinate_cursore(34, 1);
	printf("| IMPOSTAZIONI |");
	impostare_coordinate_cursore(34, 2);
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
	FILE* file_salvataggio;
	griglia griglia_gioco;
	stringa nome_file;
	char comando_utente;
	int riga;
	int colonna;
	int valore;

	partite_salvate = malloc(MAX_PARTITE_SALVATE * sizeof(stringa));
	nome_file = partita_leggere_nome(partita_corrente); // Ottiene il nome del file per il salvataggio dalla partita corrente
	do {
		stampare_schermata_di_gioco(partita_leggere_griglia(partita_corrente));
		// Legge il comando dell'utente e lo converte da minuscolo a maiuscolo se necessario
		comando_utente = nascondere_input_utente();
		comando_utente = convertire_minuscolo_maiuscolo(comando_utente);

		// Gestisce il comando di salvataggio della partita
		if (comando_utente == 'S') {
			// Apre il file in modalità scrittura binaria per salvare la partita
			file_salvataggio = fopen(stringa_leggere_array(nome_file), "wb");
			if (file_salvataggio != NULL) {
				// Scrive i dati della partita nel file
				fwrite(&partita_corrente, sizeof(partita), 1, file_salvataggio);
				fclose(file_salvataggio);

				// Visualizza l'interfaccia per caricare/selezionare slot di salvataggio
				// TODO: MANCA INTERFACCIA DI CARICARE PARTITA CONTROLLARE ASSOLUTAMENTE QUESRA PARTE

				// Legge la scelta dell'utente per lo slot di salvataggio (1-5)
				comando_utente = nascondere_input_utente();
				comando_utente = convertire_lettera_in_numero(comando_utente);

				// Verifica che la scelta sia valida (tra 1 e 5) e salva nello slot corrispondente
				if (comando_utente < 6 && comando_utente > 0) {
						partite_salvate[comando_utente - 1] = nome_file;
				}
			}
		}

		// Gestisce il comando per inserire un valore nella griglia
		if (comando_utente == 'I') {
				// Legge le coordinate e il valore dall'utente
			impostare_coordinate_cursore(68, 3);
			mostrare_cursore();
			scanf("%d", &riga);
			impostare_coordinate_cursore(71, 4);
			scanf("%d", &colonna);
			impostare_coordinate_cursore(70, 5);
			scanf("%d", &valore);

			griglia_gioco = partita_leggere_griglia(partita_corrente);
			aggiornare_griglia(&griglia_gioco, valore, riga, colonna);
			partita_scrivere_griglia(&partita_corrente, griglia_gioco);
		}
	} while (comando_utente != TASTO_ESC);

	return partite_salvate;
}

void stampare_schermata_di_gioco(griglia griglia_gioco) {
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_griglia(griglia_gioco);
	stampare_informazioni_utente();
}

void stampare_griglia(griglia griglia_gioco) {
	int i;
	int j;
	char valore_griglia;
	i = 0;
	while(i < griglia_leggere_dimensione(griglia_gioco)) {
		j = 0;
		impostare_coordinate_cursore(4, 3 + i);
		printf("|");
		while(j < griglia_leggere_dimensione(griglia_gioco)) {
			valore_griglia = convertire_numeri_in_lettere(griglia_leggere_valore(griglia_gioco, i, j));
			if (valore_griglia == '0') {
				printf(" |");
			} else {
				printf("%c|", valore_griglia);
			}
			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}
	return;
}

void stampare_informazioni_utente() {
	int i;
	i = 2;
	while(i < 25) {
		impostare_coordinate_cursore(60, i);
		printf("|");
		i = i + 1;
	}

	impostare_coordinate_cursore(62, 2);
	printf("Input:");
	impostare_coordinate_cursore(62, 3);
	printf("Riga:");
	impostare_coordinate_cursore(62, 4);
	printf("Colonna:");
	impostare_coordinate_cursore(62, 5);
	printf("Valore:");

	i = 0;
	while (i < 18) {
		impostare_coordinate_cursore(61 + i, 13);
		printf("-");
		i = i + 1;
	}
	impostare_coordinate_cursore(62, 14);
	printf("Comandi:");
	impostare_coordinate_cursore(62, 15);
	printf("S: Salva");
	impostare_coordinate_cursore(62, 16);
	printf("I: Input");
}
