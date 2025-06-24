#include "gestire_salvataggi.h"

bool_t caricare_partita(partita* partita_da_caricare) {
	bool_t caricato;
	FILE* file_partita;
	stringa* partite_salvate;
	int n_file_salvati;
	char comando_utente;
	char* path_file;
	int slot;
	bool_t selezionato_slot_vuoto;

	selezionato_slot_vuoto = FALSO;
	caricato = FALSO;
	partite_salvate = leggere_directory(CARTELLA_SALVATAGGI);
	n_file_salvati = calcolare_n_file_salvati(CARTELLA_SALVATAGGI);
	do {
		stampare_interfaccia_carica_partita();
		if (selezionato_slot_vuoto == VERO) {
			stampare_banner_errore(1, 24, 80, ERRORE_CARICAMENTO);
		}
		comando_utente = nascondere_input_utente();
		slot = convertire_lettera_in_numero(comando_utente);
		if (slot >= 1 && slot <= n_file_salvati) {
			path_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]));
			file_partita = fopen(path_file, "rb");
			if (fread(&partita_da_caricare->impostazioni_partita, sizeof(impostazioni), 1, file_partita) == 1 &&
				fread(&partita_da_caricare->griglia_partita, sizeof(griglia), 1 , file_partita) == 1  &&
				fread(&partita_da_caricare->nome_partita, sizeof(stringa), 1, file_partita) == 1)
			{
				fclose(file_partita);
				caricato = VERO;
			}
		} else {
			selezionato_slot_vuoto = VERO;
		}
	} while (comando_utente != '6' && (slot < 1 || slot > n_file_salvati));
	return caricato;
}

char* rimuovere_estensione_file(stringa nome_file) {
	char* file_no_estensione;
	int i;
	file_no_estensione = calloc(stringa_leggere_dimensione(nome_file) - strlen(ESTENSIONE_FILE) + 1, sizeof(char));
	i = 0;
	while (i < stringa_leggere_dimensione(nome_file) - strlen(ESTENSIONE_FILE)) {
		file_no_estensione[i] = stringa_leggere_carattere(nome_file, i);
		i = i + 1;
	}
	file_no_estensione[i] = '\0';
	return file_no_estensione;
}

stringa* aprire_directory(DIR* directory) {
	stringa* nome_files;
	struct dirent* file;
	int i;
	nome_files = calloc(MAX_PARTITE_SALVATE, sizeof(stringa));
	file = readdir(directory); // Ignoro il .
	file = readdir(directory); // Ignoro il ..
	i = 0;
	while ((file = readdir(directory)) != NULL) {
		stringa_scrivere_array(&nome_files[i], file->d_name, file->d_namlen);
		i = i + 1;
	}
	closedir(directory);
	return nome_files;
}

stringa* leggere_directory(char* nome_directory) {
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


int calcolare_n_file_salvati(char* nome_directory) {
	DIR* directory;
	struct dirent* file;
	int n_files;
	n_files = 0;
	if ((directory = opendir(nome_directory)) != NULL) {
		file = readdir(directory); //Ignoro il .
		file = readdir(directory); //Ignoro il ..
		while((file = readdir(directory)) != NULL) {
			n_files = n_files + 1;
		}
		closedir(directory);
	} else {
		perror("Impossibile aprire la directory");
	}

	return n_files;
}

void salvare_partita(partita partita_da_salvare) {
	bool_t salvato;
	FILE* file_salvataggio;
	stringa* partite_salvate;
	char comando_utente;
	char* path_file;
	char* vecchio_file_path;
	int slot;
	int n_file_salvati;
	partite_salvate = leggere_directory(CARTELLA_SALVATAGGI);
	n_file_salvati = calcolare_n_file_salvati(CARTELLA_SALVATAGGI);
	path_file = concatenare_due_stringhe(stringa_leggere_array(partita_leggere_nome(partita_da_salvare)), ESTENSIONE_FILE);
	path_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, path_file);
	salvato = VERO;
	do {
		stampare_interfaccia_carica_partita();
		if (salvato == FALSO) {
			stampare_banner_errore(1, 24, 80, ERRORE_SALVATAGGIO);
		}
		comando_utente = nascondere_input_utente();
		slot = convertire_lettera_in_numero(comando_utente);
		if (slot >= 1 && slot <= n_file_salvati && !salvato) {
			vecchio_file_path = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]));
			if (rename(vecchio_file_path, path_file) == 0) {
				file_salvataggio = fopen(path_file, "wb");
				if (file_salvataggio != NULL) {
					if (fwrite(&partita_da_salvare, sizeof(partita), 1, file_salvataggio) == 1) {
						fclose(file_salvataggio);
						salvato = VERO;
					} else {
						salvato = FALSO;
					}
				}
			}
		} else if(slot >= 0 && slot <= MAX_PARTITE_SALVATE && !salvato) {
			file_salvataggio = fopen(path_file, "wb");
			if (file_salvataggio != NULL) {
				if (fwrite(&partita_da_salvare, sizeof(partita), 1, file_salvataggio) == 1) {
					fclose(file_salvataggio);
					salvato = VERO;
				} else {
					salvato = FALSO;
				}
			}
		}
	} while(comando_utente != '6' && !salvato);
	return;
}

void stampare_interfaccia_carica_partita() {
	int i;
	stringa* partite_salvate;
	partite_salvate = leggere_directory(CARTELLA_SALVATAGGI);
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	impostare_coordinate_cursore(35, 1);
	printf("| CARICA |");
	impostare_coordinate_cursore(35, 2);
	printf("+--------+");
	i = 0;
	while (i < MAX_PARTITE_SALVATE) {
		impostare_coordinate_cursore(34, 10 + i);
		if (stringa_leggere_carattere(partite_salvate[i], 0) != '\0') {
			printf("%d. %s", (i + 1), rimuovere_estensione_file(partite_salvate[i]));
		} else {
			printf("%d. <SLOT VUOTO>", (i + 1));
		}
		i = i + 1;
	}
	impostare_coordinate_cursore(34, 10 + i);
	printf("%d. Indietro", (i + 1));
}
