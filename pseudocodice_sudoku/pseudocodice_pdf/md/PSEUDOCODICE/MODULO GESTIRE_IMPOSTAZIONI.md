All'interno del seguente modulo sono presenti in totale 4 funzioni, ovvero: selezionare_difficolta; selezionare_dimensione_griglia; impostare_parametri_di_gioco; inizializzare_partita.

---
### FUNZIONE  selezionare_difficolta
**INPUT**:
- difficolta_scelta, difficolta che verrà impostata a standard, numero naturale $\in$ \[0,2]

**OUTPUT**:
- difficolta_scelta, difficoltà scelta dall'utente, numero naturale $\in$ \[0,2]

**DATI DI LAVORO**:
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere

**PSEUDOCODICE**:
```C
difficolta_scelta = DIFFICOLTA_STANDARD

RIPETI
	stampa_a_schermo(menu_scelta_difficolta())
	comando_utente = nascondere_input_utente()
	SE (comando_utente = '1')
		ALLORA difficolta_scelta = DIFFICOLTA_STANDARD
	FINE		
	SE (comando_utente = '2')
		ALLORA difficolta_scelta = DIFFICOLTA_MEDIA
	FINE
	SE (comando_utente = '3') 
		ALLORA difficolta_scelta = DIFFICOLTA_DIFFICILE
	FINE
FINCHE(comando_utente < '1' OR comando_utente > '4')
```
---
### FUNZIONE  selezionare_dimensione_griglia
**INPUT**:
- dim_griglia_scelta, dimensione che inizierà come dimensione standard, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- dim_griglia_scelta, dimensione scelta dall'utente, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**DATI DI LAVORO**:
- comando_utente, variabile che assumerà il valore impostato dall'utente, carattere

**PSEUDOCODICE**:
```C
dim_griglia_scelta = DIM_GRIGLIA_STANDARD

RIPETI
	stampare_a_schermo(menu_scelta_dimensione_griglia())
	comando_utente = nascondere_input_utente()
	SE(comando_utente = '1')
		ALLORA dim_griglia_scelta = DIM_GRIGLIA_PICCOLA
	FINE
	SE(comando_utente = '2')
		ALLORA dim_griglia_scelta = DIM_GRIGLIA_STANDARD
	FINE
	SE(comando_utemte = '3')
		ALLORA dim_griglia_scelta = DIM_GRIGLIA_GRANDE
	FINE
FINCHE(comando_utente < '1' OR comando_utente > '4')
```
---
### FUNZIONE  impostare_parametri_di_gioco
**INPUT**:
- impostazioni_gioco, impostazioni del gioco, impostazioni
- difficolta_scelta, difficolta scelta dall'utente, numero naturale $\in$ \[0,2]
- dim_griglia_scelta, dimensione della griglia scelta dall'utente, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- impostazioni_gioco, impostazioni con i parametri impostati, impostazioni

**PSEUDOCODICE**:
```C
impostazioni_gioco = impostazioni_scrivere_difficolta(impostazioni_gioco, difficolta_scelta)
impostazioni_gioco = impostazioni_scrivere_dimensione_griglia(impostazioni_gioco, dim_griglia_scelta)
```
---
### FUNZIONE  inizializzare_partita
**INPUT**:
- impostazioni_utente, impostazioni dell'utente, impostazioni
- griglia, griglia scelta dall'utente, griglia
- nome_partita, nome scelto dall'utente per la partita, stringa
- partita, partita che verrà inizializzata, partita

**OUTPUT**:
- partita, partita inizializzata, partita

**PSEUDOCODICE**:
```C
partita = partita_scrivere_impostazioni(partita, impostazioni_utente)
partita = partita_scrivere_griglia(partita, griglia)
partita = partita_scrivere_nome(partita, nome_partita)
```