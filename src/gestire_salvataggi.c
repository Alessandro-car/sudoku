#include "gestire_salvataggi.h"

/*	Funzione: caricare_partita()
 * 	Descrizione: Questa funzione permette di caricare da file una partita e restituisce un booleano che indica se il caricamento è andato a buon fine o meno.
 */
bool_t caricare_partita(partita* partita_da_caricare) {
	bool_t caricato; 					//Esito del caricamento
	FILE* file_partita;					//File dal quale caricare la partita
	stringa* partite_salvate;			//Array di stringhe dei nomi delle partite salvate
	int n_file_salvati;					//Numero di partite salvate
	char comando_utente;
	char* percorso_file;				//Percorso al file dal quale caricare la partita
	int slot;							//Slot selezionato
	bool_t slot_non_esistente;		 	//Indica se è stato selezionato uno slot non esistente
	impostazioni impostazioni_partita; 	//Impostazioni di gioco da leggere da file
	stringa nome_partita;				//Nome della partita da leggere da file
	griglia griglia_partita;			//Griglia di gioco da leggere da file

	slot_non_esistente = FALSO;
	caricato = FALSO;
	partite_salvate = creare_directory(CARTELLA_SALVATAGGI);
	n_file_salvati = calcolare_n_file_salvati(CARTELLA_SALVATAGGI);
	do {
		stampare_interfaccia_carica_partita(VERO);
		//Se viene selezionato uno slot non esistente allora viene stampato il banner di errore.
		if (slot_non_esistente == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_CARICAMENTO);
			slot_non_esistente = FALSO;
		}
		comando_utente = nascondere_input_utente();
		slot = convertire_lettera_in_numero(comando_utente);
		if (slot >= 1 && slot <= n_file_salvati) {
			//Il path del file viene calcolato concatenando la cartella dove vengono salvate le partite e il nome della partita selezionato
			percorso_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]));
			file_partita = fopen(percorso_file, "rb");
			if (fread(&impostazioni_partita, sizeof(impostazioni), 1, file_partita) == 1 &&
				fread(&griglia_partita, sizeof(griglia), 1 , file_partita) == 1  &&
				fread(&nome_partita, sizeof(stringa), 1, file_partita) == 1
			) {
				partita_scrivere_impostazioni(partita_da_caricare, impostazioni_partita);
				partita_scrivere_griglia(partita_da_caricare, griglia_partita);
				partita_scrivere_nome(partita_da_caricare, nome_partita);
				fclose(file_partita);
				caricato = VERO;
			}
		} else if (slot != -1 && (slot > n_file_salvati && slot <= MAX_PARTITE_SALVATE)){
			slot_non_esistente = VERO;
		}
	} while (comando_utente != '6' && (slot < 1 || slot > n_file_salvati));
	free(partite_salvate);
	free(percorso_file);
	return caricato;
}

/*	Funzione: aprire_directory()
 * 	Descrizione: Questa funzione permette di leggere il contenuto di una directory data.
 * 	Parametri:
 * 		-directory: directory del quale leggerne il contenuto.
 *	Dato di ritorno:
 *		-nome_files, array di stringhe dei nomi dei file presenti nella directory
 */
stringa* aprire_directory(DIR* directory) {
	stringa* nome_files;
	struct dirent* file; 	//Elemento della directory
	int i;					//Indice di nome_files
	nome_files = calloc(MAX_PARTITE_SALVATE, sizeof(stringa)); //L'array di stringhe può avere al massimo MAX_PARTITE_SALVATE = 5 elementi
	file = readdir(directory); // Ignoro il .
	file = readdir(directory); // Ignoro il ..
	i = 0;
	while ((file = readdir(directory)) != NULL) {
		stringa_scrivere_array(&nome_files[i], file->d_name, file->d_namlen);
		i = i + 1;
	}
	closedir(directory);
	free(file);
	return nome_files;
}

/*	Funzione: creare_directory()
 * 	Descrizione: Questa funzione permette di creare una directory se non esiste o, in caso contrario, di aprirla e leggerne il contenuto.
 * 	Parametri:
 * 		-nome_directory: nome della directory da creare o leggere
 *	Dato di ritorno:
 *		-nome_files: array di stringhe dei nomi dei file presenti nella directory
 */
stringa* creare_directory(char* nome_directory) {
	stringa* nome_files;
	DIR* directory;
	nome_files = calloc(MAX_PARTITE_SALVATE, sizeof(stringa));
	if ((directory = opendir(nome_directory)) != NULL) {
		nome_files = aprire_directory(directory);
	} else {
		if (mkdir(nome_directory) == 0) {
			nome_files = aprire_directory(directory);
		}
	}
	return nome_files;
}

/*	Funzione: calcolare_n_file_salvati()
 * 	Descrizione: Questa funzione permette di calcolare il numero dei files presenti in una directory.
 * 	Parametri:
 * 		-nome_directory: array di caratteri che rappresentano il nome della directory della quale calcolare il numero dei file presenti in essa.
 *	Dato di ritorno:
 *		-n_files: numero di file presenti nella directory data.
 */
int calcolare_n_file_salvati(char* nome_directory) {
	DIR* directory; 		//Directory da aprire e leggere
	struct dirent* file;	//Elemento della directory
	int n_files;
	n_files = 0;
	if ((directory = opendir(nome_directory)) != NULL) {
		file = readdir(directory); //Ignoro il .
		file = readdir(directory); //Ignoro il ..
		while((file = readdir(directory)) != NULL) {
			n_files = n_files + 1;
		}
		closedir(directory);
	}
	free(file);
	return n_files;
}

/*	Funzione: salvare_partita()
 * 	Descrizione: Questa funzione permette di salvare una partita su un file.
 * 	Questa funzione stampa la medesima interfaccia di caricamento di una partita, per tanto l'utente seleziona uno slot dove salvare la partita.
 * 	Se viene selezionato uno slot già pieno, la partita salvata in quello slot viene eliminata.
 * 	Gli slot vengono usati solo per organizzare le partite salvate ma le partite non vengono ordinate tramite lo slot selezionato ma in ordine alfabetico,
 * 	in base al nome del file dato alla partita.
 * 	Parametri:
 * 		-partita_da_salvare: partita corrente da salvare su un file
 *	Dato di ritorno:
 *		-partite_salvate: array di stringhe dei nomi delle partite salvate
 */
stringa* salvare_partita(partita partita_da_salvare) {
	bool_t errore_salvataggio; 				//Indica se si è verificato un errore nel salvataggio della partita
	bool_t salvato;							//Indica se la partita è stata salvata o meno
	FILE* file_salvataggio;					//File sul quale salvare la partita
	stringa* partite_salvate;				//Insieme dei nomi dei file delle partite salvate
	char comando_utente;
	char* percorso_file;					//Path del file dove salvare la partita
	char* vecchio_percorso_file;			//Path del file dove è presente la partita da sovrascrivere
	int slot;								//Slot selezionato
	int n_file_salvati;						//Numero di file presenti nella directory
	impostazioni impostazioni_partita;		//Impostazioni della partita da salvare
	griglia griglia_partita;				//Griglia della partita da salvare
	stringa nome_partita;					//Nome della partita da salvare


	impostazioni_partita = partita_leggere_impostazioni(partita_da_salvare);
	griglia_partita = partita_leggere_griglia(partita_da_salvare);
	nome_partita = partita_leggere_nome(partita_da_salvare);
	partite_salvate = creare_directory(CARTELLA_SALVATAGGI);
	n_file_salvati = calcolare_n_file_salvati(CARTELLA_SALVATAGGI);
	//Il percorso del file viene calcolato concatenando il nome della cartella dove salvare il file, il nome della partita e l'estensione del file.
	percorso_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partita_leggere_nome(partita_da_salvare)));
	percorso_file = concatenare_due_stringhe(percorso_file, ESTENSIONE_FILE);
	errore_salvataggio = FALSO;
	salvato = FALSO;
	do {
		stampare_interfaccia_carica_partita(FALSO);
		if (errore_salvataggio == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_SALVATAGGIO);
			errore_salvataggio = FALSO;
		}
		comando_utente = nascondere_input_utente();
		slot = convertire_lettera_in_numero(comando_utente);
		//Se viene selezionato uno slot pieno, viene eliminato il vecchio file dove è salvata la partita già salvata.
		if (n_file_salvati > 0 && slot > 0 && slot <= n_file_salvati) {
			vecchio_percorso_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]));
			remove(vecchio_percorso_file);
			file_salvataggio = fopen(percorso_file, "wb");
			if (file_salvataggio != NULL) {
				if (fwrite(&impostazioni_partita, sizeof(impostazioni), 1, file_salvataggio) == 1 &&
					fwrite(&griglia_partita, sizeof(griglia), 1, file_salvataggio) == 1 &&
					fwrite(&nome_partita, sizeof(stringa), 1, file_salvataggio) == 1
				) {
					fclose(file_salvataggio);
					salvato = VERO;
					errore_salvataggio = FALSO;
				} else {
					salvato = FALSO;
					errore_salvataggio = VERO;
				}
			}
		} else if(slot > 0 && slot <= MAX_PARTITE_SALVATE) {
			//Altrimenti, se viene selezionato uno slot vuoto, viene creato un nuovo file dove salvare la partita.
			file_salvataggio = fopen(percorso_file, "wb");
			if (file_salvataggio != NULL) {
				if (fwrite(&impostazioni_partita, sizeof(impostazioni), 1, file_salvataggio) == 1 &&
					fwrite(&griglia_partita, sizeof(griglia), 1, file_salvataggio) == 1 &&
					fwrite(&nome_partita, sizeof(stringa), 1, file_salvataggio) == 1
				) {
					fclose(file_salvataggio);
					salvato = VERO;
					errore_salvataggio = FALSO;
				} else {
					salvato = FALSO;
					errore_salvataggio = VERO;
				}
			}
		}
	} while(comando_utente != '6' && salvato == FALSO);
	partite_salvate = creare_directory(CARTELLA_SALVATAGGI);
	free(percorso_file);
	free(vecchio_percorso_file);
	return partite_salvate;
}

/*	Funzione: stampare_riquadro_informazioni_partita()
 * 	Descrizione: Questa funzione stampa le informazioni di una partita, utili all'utente durante il caricamento di una partita.
 * 	Parametri:
 * 		-x, y: coordinate nelle quali iniziare a stampare le informazioni della partita
 * 		-file_path: path del file nel quale è salvata la partita
 */
void stampare_riquadro_informazioni_partita(int x, int y, char* file_path) {
	FILE* file_partita;						//File nel quale è salvata la partita
	impostazioni impostazioni_partita;		//Impostazioni della partita
	stringa nome_partita;					//Nome della partita
	griglia griglia_partita;				//Griglia della partita
	int dim_griglia;						//Dimensione della griglia
	int difficolta;							//Difficolta di gioco
	char* mess_difficolta;					//Livello di difficoltà convertito in un array di caratteri
	file_partita = fopen(file_path, "rb");
	if (fread(&impostazioni_partita, sizeof(impostazioni), 1, file_partita) == 1 &&
		fread(&griglia_partita, sizeof(griglia), 1 , file_partita) == 1  &&
		fread(&nome_partita, sizeof(stringa), 1, file_partita) == 1
	) {
		dim_griglia = impostazioni_leggere_dimensione_griglia(impostazioni_partita);
		difficolta = impostazioni_leggere_difficolta(impostazioni_partita);
		if (difficolta == DIFFICOLTA_STANDARD) {
			mess_difficolta = "Facile";
		} else if (difficolta == DIFFICOLTA_MEDIA) {
			mess_difficolta = "Media";
		} else if (difficolta == DIFFICOLTA_DIFFICILE) {
			mess_difficolta = "Difficile";
		}
		//Stampa del nome della partita
		impostare_coordinate_cursore(x, y);
		printf("Nome: %s", stringa_leggere_array(nome_partita));
		//Stampa della dimensione della griglia
		impostare_coordinate_cursore(x, y + 1);
		printf("Dimensione: %dx%d", dim_griglia, dim_griglia);
		//Stampa della difficoltà della griglia
		impostare_coordinate_cursore(x, y + 2);
		printf("Difficolta': %s", mess_difficolta);
	}
	fclose(file_partita);
	free(mess_difficolta);
	return;
}

/*	Funzione: stampare_interfaccia_carica_partita()
 * 	Descrizione: Questa funzione stampa l'interfaccia di caricamento di una partita.
 * 	Parametri:
 * 		-x, y: coordinate nelle quali iniziare a stampare le informazioni della partita
 * 		-file_path: path del file nel quale è salvata la partita
 */
void stampare_interfaccia_carica_partita(bool_t caricare) {
	int i;							//Indice della colonna del cursore
	int voci_menu_y;				//Riga nella quale iniziare a stampare le voci del menu
	int voci_menu_x;				//Colonna nella quale iniziare a stampare le voci del menu
	char *percorso_file;			//Path del file dove è salvata la partita
	stringa* partite_salvate;		//Array di stringhe dei nomi dei file delle partite salvate
	int n_partite;					//Numero di partite salvate
	int rosso;						//Tonalità di rosso del colore RGB
	int verde;						//Tonalità di verde del colore RGB
	int blu;						//Tonalità di blu del colore RGB

	rosso = 100;
	verde = 100;
	blu = 100;
	voci_menu_y = 4;
	partite_salvate = creare_directory(CARTELLA_SALVATAGGI);
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	//Stampiamo all'inizio della finestra la scritta | CARICA | o | SALVARE | centrandola rispetto alla larghezza della finestra
	if (caricare == VERO) {
		voci_menu_x = 33;
		stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| CARICA |", LARGHEZZA_FINESTRA, 1);
		//Stampiamo alla riga successiva la scritta +--------+ centrandola rispetto alla larghezza della finestra
		stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+--------+", LARGHEZZA_FINESTRA, 2);
	} else {
		voci_menu_x = 32;
		stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| SALVARE |", LARGHEZZA_FINESTRA, 1);
		//Stampiamo alla riga successiva la scritta +---------+ centrandola rispetto alla larghezza della finestra
		stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+---------+", LARGHEZZA_FINESTRA, 2);
	}
	i = 0;
	n_partite = 0;
	while (i < MAX_PARTITE_SALVATE) {
		//Se il nome della partita non è vuoto, allora vuol dire che è salvata una partita e quindi ne stampiamo le informazioni
		//In caso contrario stampiamo la scritta <SLOT VUOTO>
		if (stringa_leggere_carattere(partite_salvate[i], 0) != '\0') {
			impostare_coordinate_cursore(voci_menu_x, voci_menu_y + i + n_partite * 3);
			//CODICE ANSI PER STAMPARE STRINGA CON COLORE RGB
			printf("\x1b[38;2;%d;%d;%dm%d. Salvataggio %d%s", rosso, verde, blu, (i + 1), (i + 1), COLORE_ANSI_RESET);
			percorso_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[i]));
			stampare_riquadro_informazioni_partita(voci_menu_x + 3, voci_menu_y + i + 1 + n_partite * 3, percorso_file);
			n_partite = n_partite + 1;
		} else {
			impostare_coordinate_cursore(voci_menu_x, voci_menu_y + i + n_partite * 3);
			//CODICE ANSI PER STAMPARE STRINGA CON COLORE RGB
			printf("\x1b[38;2;%d;%d;%dm%d. <SLOT VUOTO>%s", rosso, verde, blu, (i + 1), COLORE_ANSI_RESET);
		}
		i = i + 1;
	}
	impostare_coordinate_cursore(voci_menu_x, voci_menu_y + i + n_partite * 3);
	printf("%d. Indietro", (i + 1));
	free(partite_salvate);
	free(percorso_file);
	return;
}
