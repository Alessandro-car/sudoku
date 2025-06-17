#include "gestire_partita.h"
#include "costanti.h"
#include "tipi_di_dato/griglia.h"
#include "tipi_di_dato/partita.h"
#include "utils.h"


//Funzione che esegue un controllo sulla colonna inserita in input dall'utente, essa verifica se è valida o meno.
bool_t validare_colonna_input(int colonna, int dim_griglia) {
	bool_t validato;       //Indica se la colonna è valida o meno

	validato = VERO;       //validato = Vero
  if(colonna < 0 || colonna > dim_griglia){
  	validato = FALSO;      //validato = Falso
  }
  return validato;
}

//Funzione che esegue un controllo sulla colonna inserita e verifica se il numero da inserire è gia presente o meno
bool_t controllare_colonna(griglia griglia, int colonna, int numeri_da_inserire, int dimensione_griglia) {
  bool_t corretto;           //Indica se il numero può essere inserito o meno
  int i;
  corretto = VERO;           //corretto = Vero
  i = 1;
  while(i < dimensione_griglia){
      if(griglia_leggere_valore(griglia, i, colonna) == numeri_da_inserire){
      	corretto = FALSO;   //corretto = Falso
      }
			i = i + 1;
  }
	return corretto;
}

//La seguente funzione permette di verificare se un valore inserito dall'utente può venir considerato valido
bool_t validare_valore_input(int valore, int dim_griglia) {
	int validato; //booleano che che varrà come output
	int dim_griglia_carattere;

	validato = VERO; //Booleano inizializzato a VERO
	dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

	if(dim_griglia >= DIM_GRIGLIA_GRANDE && (valore < CHAR_0 || (valore > CHAR_9 && valore < CHAR_A) || valore > dim_griglia_carattere )) { /*verifica che non  si vada incontro ai vincoli sulla dim_griglia e sul valore*/
		validato = FALSO; //Nel caso allora validato = FALSO
	} else {
			if(dim_griglia <= DIM_GRIGLIA_GRANDE && (valore < CHAR_0 || valore > CHAR_9))  { /*verifica che non  si vada incontro ai vincoli sulla dim_griglia e sul valore*/
				validato = VERO;
				dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

				if(dim_griglia >= DIM_GRIGLIA_GRANDE && (valore < CHAR_0 || (valore > CHAR_9 && valore < CHAR_A) || valore > dim_griglia_carattere )) {
					validato = FALSO;
				} else {
					if(dim_griglia < DIM_GRIGLIA_GRANDE && (valore < CHAR_0 || valore > CHAR_9))  {
						validato = FALSO;
					}
				}
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
	bool_t corretto = VERO;
	int i = riga;
	while (i < riga + dimensione_regione) {
		int j = colonna;
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

bool_t validare_riga_input(int riga, int dim_griglia) {
	bool_t validato = VERO;
	if (riga < 0 || riga > dim_griglia) {
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

    // Inizializziamo il risultato come VERO (mettiamo inizialmente che il numero può essere inserito)
    corretto = VERO;
    j = 0;

    // Scorriamo tutte le colonne della riga specificataa
    while (j <= dimensione_sudoku) {
        // Leggiamo il valore presente nella cella corrente (riga, colonna j)
        valore_cella = griglia_leggere_valore(sudoku, riga, j);

        // Se il valore nella cella corrente è uguale al numero che vogliamo inserire,
        // allora il numero non può essere inserito in questa riga
        if (valore_cella == numero_da_inserire) {
            corretto = FALSO;
        }

        // Passiamo alla colonna successiva
        j = j + 1;
    }

    // Restituiamo VERO se il numero può essere inserito, FALSO altrimenti
    return corretto;
}

void stampare_interfaccia_impostazioni(void) {

    printf("Menu opzioni\n\n");
     printf("%*s| IMPOSTAZIONI |\n", 34, "");
     printf("%*s+--------------+\n", 34, "");
     printf("\n\n\n\n\n\n\n\n"); // 8 righe vuote
     printf("%*s\t 1. Scegli difficolta'\n", 31, "");
     printf("%*s\t 2. Scegli dimensione\n", 31, "");
     printf("%*s\t 3. Inserisci nome partita\n", 31, "");
     printf("%*s\t 4. Prosegui\n", 31, "");
     printf("%*s\t 5. Torna indietro\n", 31, "");
     getchar();
     return 0;
}

partita* giocare_partita(partita partita_corrente) {
    FILE* file_salvataggio;
    int comando_utente;
    int riga, colonna, valore;
    stringa nome_file;

    // Ottiene il nome del file per il salvataggio dalla partita corrente
    nome_file = partita_leggere_nome(partita_corrente);

    // Loop principale del gioco - continua fino a quando l'utente non preme ESC (codice ASCII 27)
    do {
        // Visualizza l'interfaccia di gioco
     stampare_interfaccia_impostazioni();
        // Legge il comando dell'utente e lo converte da minuscolo a maiuscolo se necessario
        comando_utente = getchar();
        comando_utente = convertire_minuscolo_maiuscolo(comando_utente);

        // Gestisce il comando di salvataggio della partita
        if (comando_utente == 'S') {
            // Apre il file in modalità scrittura binaria per salvare la partita
            file_salvataggio = fopen(nome_file.caratteri, "wb");
            if (file_salvataggio != NULL) {
                // Scrive i dati della partita nel file
                fwrite(&partita_corrente, sizeof(partita), 1, file_salvataggio);
                fclose(file_salvataggio);

                // Visualizza l'interfaccia per caricare/selezionare slot di salvataggio
                /* MANCA INTERFACCIA DI CARICARE PARTITA
                 CONTROLLARE ASSOLUTAMENTE QUESRA PARTE.


				*/
                // Legge la scelta dell'utente per lo slot di salvataggio (1-5)
                comando_utente = getchar();
                comando_utente = convertire_lettera_in_numero(comando_utente);

                // Verifica che la scelta sia valida (tra 1 e 5) e salva nello slot corrispondente
                if (comando_utente < NUM_6 && comando_utente > NUM_0) {
                    partite_salvate[comando_utente - NUM_1] = partita_corrente;
                }
            }
        }

        // Gestisce il comando per inserire un valore nella griglia
        if (comando_utente == 'I') {
            // Legge le coordinate e il valore dall'utente
            printf("Inserisci riga: ");
            scanf("%d", &riga);
            printf("Inserisci colonna: ");
            scanf("%d", &colonna);
            printf("Inserisci valore: ");
            scanf("%d", &valore);

            // Ottiene la griglia corrente dalla partita
            griglia griglia_corrente = partita_leggere_griglia(partita_corrente);

            // Aggiorna la griglia con il nuovo valore se l'input è valido
            griglia_corrente = aggiornare_griglia(griglia_corrente, valore, riga, colonna);

            // Scrive la griglia aggiornata nella partita
            partita_corrente = partita_scrivere_griglia(partita_corrente, griglia_corrente);
        }

    } while (comando_utente != NUM_27); // Continua fino alla pressione del tasto ESC

    return partite_salvate;
}
