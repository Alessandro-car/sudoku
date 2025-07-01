All'interno del seguente modulo sono presenti in totale 9 funzioni, ovvero: controllare_colonna; controllare_regione; controllare_riga; validare_colonna_input; validare_input_utente;  validare_riga_input; validare_valore_input; verificare_coordinate; verificare_numero_da_inserire.

---
### FUNZIONE  controllare_colonna
**INPUT**:
- colonna, colonna in cui controllare se il valore è già stato inserito, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- griglia, griglia al cui interno è presente la colonna da controllare, griglia
- numero_da_inserire, numero da verificare che non sia presente nella colonna,  numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- corretto, indica se la cella è libera con VERO, booleano

**DATI DI LAVORO**:
- i, indice che permette di scorrere la griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- valore_cella, valore all'interno della cella, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
i = 1

MENTRE( i <= leggere_dimensione_griglia(griglia) )
	valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, collona))
	SE(valore_cella = numero_da_inserire)
		ALLORA corretto = FALSO
	FINE
	i = i + 1
FINE
```
---
### FUNZIONE  controllare_regione
**INPUT**:
- griglia, griglia al cui interno è presente la regione da controllare, griglia
- riga, indica la riga della griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- colonna, indica la colonna della griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- numero_da_inserire, numero da verificare che non sia presente nella regione, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- corretto, indica se il numero può essere inserito con VERO,  booleano

**DATI DI LAVORO**:
- colonna_inizio_regione, indica l'inizio della colonna della regione, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- dimensione_regione, dimensione della regione, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- i, indice che permette di scorrere la griglia,  numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- j, indice che permette di scorrere la griglia,  numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- riga_inizio_regione, indica l'inizio della riga della regione, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- valore_cella, valore della cella, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
dimensione_regione = calcolare_radice_quadrata(griglia_leggere_dimensione(griglia))
riga_inizio_regione = riga - calcolare_resto_intero(riga, dimensione_regione)
colonna_inizio_regione = colonna - calcolare_resto_intero(colonna, dimensione_regione)
corretto = VERO
i = riga_inizio_regione
MENTRE(i < riga_inizio_regione + dimensione_regione)
	j = colonna_inizio_regione
	MENTRE(j < colonna_inizio_regione + dimensione_regione)
		valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, j))
		SE(valore_cella = numero_da_inserire)
			ALLORA corretto = FALSO
		FINE
		j = j + 1
	FINE
	i = i + 1
FINE
```
---
### FUNZIONE  controllare_riga
**INPUT**:
- griglia, griglia al cui interno è presente la riga da controllare, griglia
- riga,  riga in cui controllare se il valore è già stato inserito, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- numero_da_inserire, numero da verificare che non sia presente nella riga,  numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- corretto, indica se la cella è libera con VERO,  booleano

**DATI DI LAVORO**:
- j, indice per scorrere la griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- valore_cella, valore della cella, numero naturale >0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
corretto = VERO
j = 1

MENTRE(j <= griglia_leggere_dimensione(griglia))
	valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, riga, j))
	SE(valore_cella = numero_da_inserire)
		ALLORA corretto = FALSO
	FINE
	j = j + 1
FINE
```
---
### FUNZIONE  validare_colonna_input
**INPUT**:
- colonna, valore fornito dall'utente per specificare la colonna a cui vuole riferirsi durante il gioco, naturale > 0 <= DIM_GRIGLIA_GRANDE
- dim_griglia, dimensione della griglia, naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- validato, indica se il valore della colonna fornito dall'utente è valido con VERO, booleano

**PSEUDOCODICE**:
```C
validato = VERO
SE(colonna <= 0 OR colonna > dim_griglia) 
	ALLORA validato = FALSO
FINE
```
---
### FUNZIONE  validare_input_utente
**INPUT**:
- riga, valore fornito dall'utente per specificare la riga a cui vuole riferirsi durante il gioco, naturale > 0 <= DIM_GRIGLIA_GRANDE
- colonna, valore fornito dall'utente per specificare la colonna a cui vuole riferirsi durante il gioco, naturale > 0 <= DIM_GRIGLIA_GRANDE
- valore, valore fornito dall'utente per specificare cosa vuole inserire all'interno di una 'cella' selezionata, carattere
- griglia_gioco, griglia del gioco, griglia

**OUTPUT**:
- validato, indica se la riga, colonna e valore inseriti dall'utente sono validi con VERO, booleano

**DATI DI LAVORO**:
- dim_griglia, indica la dimensione della griglia, naturale > 0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
dim_griglia = griglia_leggere_dimensione(griglia_gioco)
valore = convertire_minuscolo_maiuscolo(valore)
validato = FALSO

SE((validare_riga_input(riga, dim_griglia)= VERO) AND (validare_colonna_input(colonna, dim_griglia) = VERO) AND (validare_valore_input(valore, dim_griglia) = VERO)) 
	ALLORA validato = VERO
FINE
```
---
### FUNZIONE  validare_riga_input
**INPUT**:
- riga, valore fornito dall'utente per specificare la riga a cui vuole riferirsi durante il gioco, naturale > 0 <=DIM_GRIGLIA_GRANDE
- dim_griglia, dimensione griglia, naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- validato, indica se la riga è valida con VERO, booleano

**PSEUDOCODICE**:
```C
validato = VERO
SE(riga <= 0 OR riga > dim_griglia) 
	ALLORA validato = FALSO
FINE
```
---
### FUNZIONE  validare_valore_input
**INPUT**:
- valore, valore fornito dall'utente per specificare cosa vuole inserire all'interno di una 'cella' selezionata, carattere
- dim_griglia, dimensione della griglia, naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- validato, indica se il valore inserito è valido con VERO, booleano

**DATI DI LAVORO**:
- dim_griglia_carattere, indica la dimensione della griglia convertita in lettera, carattere

**PSEUDOCODICE**:
```C
validato = VERO
dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia)

SE(valore < CHAR_0 OR (valore > CHAR_9 AND valore < CHAR_A) OR valore > dim_griglia_carattere)
	ALLORA validato = FALSO	  
FINE
```
---
### FUNZIONE  verificare_coordinate
**INPUT**:
- coordinata_x, posizione della riga che si vuole controllare, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- coordinata_y, posizione della colonna che si vuole controllare, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- griglia_gioco, griglia del gioco con i valori già inseriti, griglia

**OUTPUT**:
- validato, indica se le coordinate da controllare sono valide con FALSO, booleano

**PSEUDOCODICE**:
```C
validato = VERO

SE(valore_griglia_leggere_valore(griglia_leggere_valore(griglia_gioco, coordinata_x, coordinata_y)) <> 0) 
   ALLORA validato = FALSO
FINE
```
---
### FUNZIONE  verificare_numero_da_inserire
**INPUT**:
- griglia, griglia della partita in cui inserire il valore, griglia
- numero_da_inserire, numero da inserire all'interno della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- riga, indica la riga dove si vuole inserire il numero da verificare, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- colonna, indica la colonna dove si vuole inserire il numero da verificare, numero naturale >0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- corretto, indica se il valore da voler inserire è valido con VERO, booleano

**PSEUDOCODICE**:
```C
corretto = FALSO

SE((controllare_riga(griglia, riga, numero_da_inserire) = VERO) AND (controllare_colonna(griglia, colonna, numero_da_inserire) = VERO) AND (controllare_regione(griglia, riga, colonna, numero_da_inserire) = VERO))
	ALLORA corretto = VERO
FINE
```