All'interno del seguente modulo sono presenti in totale 2 funzioni, ovvero: iniziare_partita; menu_principale

---
### FUNZIONE  iniziare_partita
**INPUT**:
- partite_salvate, insieme delle partite salvate, file_binario

**OUTPUT**:
- partite_salvate, insieme delle partite salvate aggiornato, array di file_binario

**DATI DI LAVORO**:
- uscito, indica se l'utente è uscito correttamente con VERO, booleano
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere
- difficolta_scelta, difficolta scelta dall'utente, numero naturale $\in$ \[0,2]
- dim_griglia_scelta, dimensione scelta della griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- nome_partita, nome della partita scelto dall'utente, stringa
- griglia_sudoku, griglia della partita, griglia
- impostazioni_gioco, impostazioni del gioco, impostazioni
- nome_impostato, indica se il nome è stato impostato correttamente con VERO, booleano
- partita_da_giocare, partita che verrà iniziata, partita
- nome_vuoto, indica se il nome inserito è vuoto con VERO, booleano
- nome_errato, indica se il nome inserito è errato con VERO, booleano

**PSEUDOCODICE**:
```C
nome_errato = FALSO
nome_impostato = FALSO
nome_vuoto = FALSO
uscito = FALSO
difficolta_scelta = DIFFICOLTA_STANDARD
dim_griglia_scelta = DIM_GRIGLIA_STANDARD
stringa = stringa_scrivere_dimensione(nome_partita, 0)

RIPETI
	stampare_a_schermo(stampare_interfaccia_impostazioni())  
	SE(nome_impostato = FALSO AND nome_vuoto = VERO)
		ALLORA stampare_a_video(stampare_banner_errore(ERRORE_NOME_FILE_VUOTO))
		ALTRIMENTI 
			SE(nome_impostato = FALSO AND nome_errato = VERO)
				ALLORA stampare_a_video(stampare_banner_errore(ERRORE_NOME_FILE_ERRATO))
				ALTRIMENTI 
					SE(nome_impostato = FALSO)
						ALLORA stampare_a_video(stampare_banner_errore(ERRORE_NOME_FILE))
					FINE
			FINE
	FINE
	
	nome_errato = FALSO
	nome_vuoto = FALSO
	comando_utente = nascondere_input_utente()
	SE(comando_utente = '1')
		ALLORA difficolta_scelta = selezionare_difficolta(difficolta_scelta)
	FINE
	SE(comando_utente = '2')
		ALLORA dim_griglia_scelta = selezionare_dimensione_griglia(difficolta_scelta)
	FINE
	SE(comando_utente = '3')
		ALLORA 
			impostare_coordinate_cursore()
			stampare_a_video(':')
			mostrare_cursore()
			nome_partita = prendere_input_stringa_limitato(nome_partita, DIM_MAX_STRINGA - calcolare_lunghezza_array_caratteri(ESTENSIONE_FILE))
			SE(controllare_caratteri_stringa(nome_partita, CARATTERI_NOME_FILE_NON_AMMESSI) = FALSO)
				ALLORA 
					nome_impostato = FALSO 
					nome_errato = VERO
				ALTRIMENTI 
					SE(stringa_leggere_dimensione(nome_partita)<= 0)
						ALLORA 
							nome_impostato = FALSO
							nome_vuoto = VERO
						ALTRIMENTI nome_impostato = VERO
					FINE		
			FINE
	FINE
	SE(comando_utente = '4' AND nome_impostato = VERO)
		ALLORA 
			impostazioni_gioco = impostare_paramentri_di_gioco(impostazioni_gioco, difficolta_scelta, dim_griglia_scelta)
			griglia_sudoku = inizializzare_griglia(griglia_sudoku, impostazioni_gioco)
			partita_da_giocare = inizializzare_partita(impostazioni_gioco, griglia_sudoku, nome_partita, partita_da_giocare)
			partite_salvate = scrivere_elemento(partite_salvate, giocare_partita(partita_da_giocare))
			uscito = VERO
	FINE
	FINCHE(comando_utente <> '5' AND uscito <> VERO)
```
---
### FUNZIONE  menu_principale
**INPUT**:
- partite_salvate, insieme delle partite salvate, array di file_binario

**OUTPUT**:
- partite_salvate, insieme delle partite salvate aggiornato, array di file_binario

**DATI DI LAVORO**:
- partita_caricata, partita caricata, partita
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere
- caricato, indica se la partita è stata caricata con VERO, booleano

**PSEUDOCODICE**:
```C
RIPETI
	stampare_a_schermo(stampare_interfaccia_menu_principale())	
	comando_utente = nascondere_input_utente()
	SE(comando_utente = '1')
		ALLORA iniziare_partita(partite_salvate)
	FINE
	SE(comando_utente = '2')
		ALLORA caricato = caricare_partita(partita_caricata)
		SE(caricato = VERO)
			ALLORA partite_salvate = scrivere_elemento(partite_salvate, giocare_partita(partita_caricata))	
		FINE
	FINE
FINCHE(comando_utente <> '3')
```