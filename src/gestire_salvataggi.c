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
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_CARICAMENTO);
			selezionato_slot_vuoto = FALSO;
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
		} else if (slot != -1 && (slot < 0 || slot > n_file_salvati)){
			selezionato_slot_vuoto = VERO;
		}
	} while (comando_utente != '6' && (slot < 1 || slot > n_file_salvati));
	free(partite_salvate);
	free(path_file);
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
	free(file);
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
	free(file);
	return n_files;
}

void salvare_partita(partita partita_da_salvare) {
	bool_t errore_salvataggio;
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
	salvato = FALSO;
	errore_salvataggio = FALSO;
	do {
		stampare_interfaccia_carica_partita();
		if (errore_salvataggio == VERO) {
			stampare_banner_errore(BANNER_ERRORE_POS_X, BANNER_ERRORE_POS_Y, LARGHEZZA_FINESTRA, ERRORE_SALVATAGGIO);
			errore_salvataggio = FALSO;
		}
		comando_utente = nascondere_input_utente();
		slot = convertire_lettera_in_numero(comando_utente);
		if (slot >= 1 && slot <= n_file_salvati && salvato == FALSO) {
			vecchio_file_path = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]));
			if (rename(vecchio_file_path, path_file) == 0) {
				file_salvataggio = fopen(path_file, "wb");
				if (file_salvataggio != NULL) {
					if (fwrite(&partita_da_salvare, sizeof(partita), 1, file_salvataggio) == 1) {
						fclose(file_salvataggio);
						salvato = VERO;
						errore_salvataggio = FALSO;
					} else {
						salvato = FALSO;
						errore_salvataggio = VERO;
					}
				}
			}
		} else if(slot > 0 && slot <= MAX_PARTITE_SALVATE && salvato == FALSO) {
			file_salvataggio = fopen(path_file, "wb");
			if (file_salvataggio != NULL) {
				if (fwrite(&partita_da_salvare, sizeof(partita), 1, file_salvataggio) == 1) {
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
	free(partite_salvate);
	free(path_file);
	free(vecchio_file_path);
	return;
}

void stampare_riquadro_informazioni_partita(int x, int y, char* file_path) {
	FILE* file_partita;
	partita partita_letta;
	impostazioni impostazioni_partita;
	int dim_griglia;
	stringa nome_partita;
	int difficolta;
	char* mess_difficolta;
	file_partita = fopen(file_path, "rb");
	if (fread(&partita_letta.impostazioni_partita, sizeof(impostazioni), 1, file_partita) == 1 &&
		fread(&partita_letta.griglia_partita, sizeof(griglia), 1 , file_partita) == 1  &&
		fread(&partita_letta.nome_partita, sizeof(stringa), 1, file_partita) == 1) {
		impostazioni_partita = partita_leggere_impostazioni(partita_letta);
		nome_partita = partita_leggere_nome(partita_letta);
		dim_griglia = impostazioni_leggere_dimensione_griglia(impostazioni_partita);
		difficolta = impostazioni_leggere_difficolta(impostazioni_partita);
		if (difficolta == DIFFICOLTA_STANDARD) {
			mess_difficolta = "Facile";
		} else if (difficolta == DIFFICOLTA_MEDIA) {
			mess_difficolta = "Media";
		} else if (difficolta == DIFFICOLTA_DIFFICILE) {
			mess_difficolta = "Difficile";
		}
		impostare_coordinate_cursore(x + 3, y);
		printf("Nome: %s", stringa_leggere_array(nome_partita));
		impostare_coordinate_cursore(x + 3, y + 1);
		printf("Dimensione: %dx%d", dim_griglia, dim_griglia);
		impostare_coordinate_cursore(x + 3, y + 2);
		printf("Difficolta': %s", mess_difficolta);
	}
	fclose(file_partita);
	free(mess_difficolta);
	return;
}

void stampare_interfaccia_carica_partita() {
	int i;
	int voci_menu_y;
	int voci_menu_x;
	char *path_file;
	stringa* partite_salvate;
	int n_partite;
	int rosso;
	int verde;
	int blu;

	rosso = 100;
	verde = 100;
	blu = 100;
	voci_menu_x = 32;
	voci_menu_y = 4;
	partite_salvate = leggere_directory(CARTELLA_SALVATAGGI);
	pulire_schermo();
	disegnare_riquadro_interfaccia();
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "| CARICA |", LARGHEZZA_FINESTRA, 1);
	stampare_centrato_colorato(COLORE_ANSI_BIANCO, "+--------+", LARGHEZZA_FINESTRA, 2);
	i = 0;
	n_partite = 0;
	while (i < MAX_PARTITE_SALVATE) {
		if (stringa_leggere_carattere(partite_salvate[i], 0) != '\0') {
			impostare_coordinate_cursore(voci_menu_x, voci_menu_y + i + n_partite * 3);
			//CODICE ANSI PER STAMPARE STRINGA CON COLORE RGB
			printf("\x1b[38;2;%d;%d;%dm%d. Salvataggio %d%s", rosso, verde, blu, (i + 1), (i + 1), COLORE_ANSI_RESET);
			path_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[i]));
			stampare_riquadro_informazioni_partita(voci_menu_x, voci_menu_y + i + 1 + n_partite * 3, path_file);
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
	free(path_file);
	return;
}
