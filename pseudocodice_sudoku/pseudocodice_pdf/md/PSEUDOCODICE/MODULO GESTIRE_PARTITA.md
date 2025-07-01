all'interno del seguente modulo è presente in totale una funzione, ovvero: giocare_partita

---
### FUNZIONE  giocare_partita
**INPUT**:
- partita_corrente, partita attualmente in gioco, partita

**OUTPUT**:
- partite_salvate, insieme di tutte le partite salvate, array di file_binario

**DATI DI LAVORO**:
- griglia_gioco, griglia del gioco, griglia
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere
- riga, riga della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- colonna, colonna della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- valore, valore da scrivere all'interno della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- valore_modificabile, indica se il valore è modificabile con VERO, booleano
- input_corretto, indica se l'input è corretto con VERO, booleano

**PSEUDOCODICE**:
```C
valore_modificabile = VERO
input_corretto = VERO

RIPETI
	stampare_schermata_di_gioco(partita_corrente)
	SE(valore_modificabile = FALSO)
		ALLORA stampare_banner_errore(ERRORE_VALORE_NON_MODIFICABILE)
		ALTRIMENTI 
			 SE(input_corretto = FALSO)
				ALLORA stampare_banner_errore(ERRORE_INPUT_ERRATI)
			FINE
	FINE
	
	valore_modificabile = VERO
	input_corretto = VERO
	comando_utente = nascondere_input_utente()
	comando_utente = convertire_minuscolo_maiuscolo(comando_utente)
	
	SE(comando_utente = 'S')
		ALLORA	partite_salvate = scrivere_elemento(partite_salvate, partita_corrente)
	FINE
	
	SE(comando_utente = 'I')
		ALLORA
			impostare_coordinate_cursore()
			mostrare_cursore()
			riga = prendere_input_carattere_limitato()
			impostare_coordinate_cursore()
			colonna = prendere_input_carattere_limitato()
			impostare_coordinate_cursore()
			valore = prendere_input_carattere_limitato()	
			riga = convertire_minuscolo_maiuscolo(riga)
			colonna = convertire_minuscolo_maiuscolo(colonna)	
			valore = convertire_minuscolo_maiuscolo(valore)
			griglia_gioco = partita_leggere_griglia(partita_corrente)
			input_corretto = validare_valore_input(convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna), valore, griglia_gioco)
		
			SE(input_corretto = VERO)
				ALLORA 
					valore_modificabile = valore_griglia_leggere_modificabile(griglia_leggere_valore(griglia_gioco, convertire_lettera_in_numero(riga)-1, convertire_lettera_in_numero(colonna)-1))
			FINE
			
			SE(valore_modificabile = VERO AND input_corretto = VERO)
				ALLORA 
					griglia_gioco = aggiornare_griglia(griglia_gioco, convertire_lettera_in_numero(valore), convertire_lettera_in_numero(riga), convertire_lettera_in_numero(colonna))
				partita_corrente = partita_scrivere_griglia(partita_corrente, griglia_gioco)
			FINE
	FINE
FINCHE(comando_utente <> TASTO_ESC)
```