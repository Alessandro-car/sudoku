all'interno del seguente modulo sono presenti in totale 2 funzioni, ovvero: 
caricare_partita; salvare_partita

---
### FUNZIONE  caricare_partita
**INPUT**:
- partita_da_caricare, partita che verrà caricata, partita

**OUTPUT**:
- caricato, indica se il caricamento della partita è andato a buon fine con VERO, booleano

**DATI DI LAVORO**:
- file_partita, file della partita da caricare, file_binario
- partite_salvate, insieme delle partite salvate, array di stringa
- n_file_salvati, rappresenta il numero dei file salvati in partite_salvate, numero naturale > 0 <=MAX_PARTITE_SALVATE 
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere
- percorso_file, rappresenta l'intero percorso del file, array di caratteri
- slot, slot di salvataggio, numero naturale > 0
- slot_non_esistente, indica se lo slot selezionato è vuoto con VERO, booleano

**PSEUDOCODICE**:
```C
slot_non_esistente = FALSO
caricato = FALSO
partite_salvate = creare_directory(CARTELLA_SALVATAGGI)
n_file_salvati = calcolare_n_file_salvati(CARTELLA_SALVATAGGI)

RIPETI
	stampare_a_schermo(stampare_interfaccia_carica_partita())
	SE(slot_non_esistente = VERO)
		ALLORA	
			stampare_a_schermo(stampare_banner_errore(ERRORE_CARICAMENTO))
			slot_non_esistente = FALSO
	FINE
	
	comando_utente = nascondere_input_utente()
	slot  = convertire_lettera_in_numero(comando_utente)
	
	SE(slot  >= 1 AND <= slot )
		ALLORA 
			percorso_file = concatenerare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]))
		SE(leggere_elemento(file_partita))
			ALLORA 
				partita_da_caricare = partita_scrivere_impostazioni(partita_da_caricare, impostazioni_partita)
				partita_da_caricare = partita_scrivere_griglia(partita_da_caricare, griglia_partita)
				partita_da_caricare = partita_scrivere_nome(partita_da_caricare, nome_partita)
				caricato = VERO
		FINE	
		ALTRIMENTI 
			SE(slot <> -1 AND slot => n_file_salvati AND slot <= MAX_PARTITE_SALVATE))
				ALLORA slot_non_esistente = VERO
			FINE
	FINE
FINCHE(comando_utente <> '6' AND (slot < 1 OR slot > n_file_salvati))
```
---
### FUNZIONE  salvare_partita
**INPUT**:
- partite_salvate, insieme delle partite salvate, array di file_binario
- nuova_partita, indica se la nuova partita è iniziata con VERO, booleano

**OUTPUT**:
- partite_salvate, insieme delle partite salvate aggiornato, array di file_binario

**DATI DI LAVORO**:
- errore_salvataggio, indica se c'è stato un errore di salvataggio con VERO, booleano
- salvato, indica se un file è stato salvato con VERO, booleano
- file_salvataggio, file di salvataggio, file_binario
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere
- percorso_file, percorso del file, carattere
- vecchio_file_percorso, rappresenta il vecchio percorso del file, carattere
- slot, valore che rappresenta lo slot di salvataggio, numero naturale >0
- n_file_salvati, numero dei file salvati, numero naturale > 0 <= MAX_PARTITE_SALVATE
- impostazioni_partita, impostazioni della partita, impostazioni
- griglia_partita, griglia della partita, griglia
- nome_partita, nome della partita, stringa

**PSEUDOCODICE**:
```C
impostazioni_partita = partita_leggere_impostazioni(partita_da_salvare)
griglia_partita = partita_leggere_griglia(partita_da_salvare)
nome_partita = partita_leggere_nome(partita_da_salvare)
partite_salvate = creare_directory(CARTELLA_SALVATAGGI)
n_file_salvati = calcolare_n_file_salvati(CARTELLA_SALVATAGGI)
percorso_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partita_leggere_nome(partita_da_salvare)))
percorso_file = concatenare_due_stringhe(percorso_file, ESTENSIONE_FILE)
salvato = FALSO
errore_salvataggio = FALSO

SE(nuova_partita <> FALSO)
	ALLORA gestire_avviso_salvataggio()
FINE

RIPETI
	stampare_a_schermo(stampare_interfaccia_carica_partita())
	SE(errore_salvataggio = VERO)
		ALLORA 
			stampare_a_schermo(stampare_banner_errore(ERRORE_SALVATAGGIO))
			errore_salvataggio = FALSO
	FINE
	
	comando_utente = nascondere_input_utente()
	slot = convertire_lettera_in_numero(comando_utente)
	
	SE(slot >= 0 AND slot <= n_file_salvati)
		ALLORA 
			vecchio_percorso_file = concatenare_due_stringhe(CARTELLA_SALVATAGGI, stringa_leggere_array(partite_salvate[slot - 1]))
			remove(vecchio_percorso_file)
		SE(file_salvataggio <> NULL)
			ALLORA 
				SE(scrivere_elemento(file_salvataggio, partita_da_salvare))
					ALLORA 
						salvato = VERO
						errore_salvataggio = FALSO
					ALTRIMENTI
						salvato = FALSO
						errore_salvataggio = VERO
					
				FINE		
		FINE	 
		ALTRIMENTI 
			SE(slot > 0 AND slot <= MAX_PARTITE_SALVATE)
				SE(file_salvataggio <> NULL)
					ALLORA 	
						SE(scrivere_elemento(file_salvataggio, partita_da_scrivere))
							ALLORA 
								salvato = VERO
								errore_salvataggio = FALSO
							ALTRIMENTI
								salvato = FALSO
								errore_salvataggio = VERO
						FINE 	
	            FINE
			FINE
FINCHE(comando_utente <> '6' AND salvato = FALSO)
partite_salvate = scrivere_elemento(partite_salvate, creare_directory(CARTELLA_SALVATAGGI))
```