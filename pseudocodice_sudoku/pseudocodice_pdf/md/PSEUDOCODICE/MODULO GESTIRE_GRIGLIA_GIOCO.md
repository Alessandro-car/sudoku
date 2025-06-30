
---
All'interno del seguente modulo sono presenti in totale 5 funzioni, ovvero: n_numeri_di_griglia; aggiornare_griglia; azzerare_griglia; inizializzare_griglia; riempire_griglia.

---
### FUNZIONE  n_numeri_di_griglia
**INPUT**:
- impostazioni_gioco, impostazioni del gioco, impostazioni

**OUTPUT**:
- numeri_da_inserire_in_griglia, numero di valori inseriti nella griglia, numero naturale >0

**DATI DI LAVORO**:
- difficolta, difficoltà scelta dall'utente, numero naturale \in \[0,2]
- dimensione_griglia, dimensione della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
difficolta = impostazioni_leggere_difficolta(impostazioni_gioco)
dimensione_griglia = griglia_leggere_dimensione(impostazioni_gioco)

SE(difficolta = 0) 
	ALL0RA numeri_da_inserire_in_griglia = ((dimensione_griglia)^2 *PERCENTUALE_DIFFICOLTA_FACILE)
FINE
SE(difficolta = 1) 
	ALLORA numeri_da_inserire_in_griglia = ((dimensione_griglia)^2 * PERCENTUALE_DIFFICOLTA_MEDIA)
FINE

SE(difficolta = 2) 
	ALLORA numeri_da_inserire_in_griglia = ((dimensione_griglia)^2 *PERCENTUALE_DIFFICOLTA_DIFFICILE)
FINE
```
---
### FUNZIONE  aggiornare_griglia
**INPUT**:
- griglia, griglia che verrà aggiornata, griglia
- valore, valore che verrà inserito all'interno della griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- riga, riga selezionata dall'utente per inserire il valore, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- colonna, colonna selezionata dall'utente per inserire il valore, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- griglia, griglia aggiornata con il valore, griglia

**DATI DI LAVORO**:
- val, valore della griglia che verrà aggiornato con valore, valore_griglia

**PSEUDOCODICE**:
```C
val = valore_griglia_scrivere_valore(val,valore)
val = valore_griglia_scrivere_modificabile(val, VERO)
griglia = griglia_scrivere_valore(griglia, riga -1, colonna -1, val)
```
---
### FUNZIONE  azzerare_griglia
**INPUT**:
- griglia_gioco, griglia da azzerata, griglia

**OUTPUT**:
- griglia_gioco, griglia azzerata, griglia

**DATI DI LAVORO**:
- i, indice che permette di scorrere la griglia, numero naturale > 0  <= DIM_GRIGLIA_GRANDE
- j, indice che permette di scorrere la griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- val, valore che verrà impostato a 0, valore_griglia

**PSEUDOCODICE**:
```C
i = 1

MENTRE(i <= griglia_leggere_dimensione(griglia_gioco))
	j = 1
	MENTRE(j <= griglia_leggere_dimensione(griglia_gioco))
		val = valore_griglia_scrivere_modificabile(val, VERO)
		val = valore_griglia_scrivere_valore(val, 0)
		griglia_gioco = griglia_scrivere_valore(griglia_gioco, i, j, val)
		j = j + 1
	FINE
	i = i + 1
FINE 
```
---
### FUNZIONE  inizializzare_griglia
**INPUT**:
- griglia_gioco, griglia da inizializzare, griglia
- impostazioni_selezionate, impostazioni selezionate dall'utente per inizializzare la griglia, impostazioni

**OUTPUT**:
- griglia_gioco, griglia inizializzata con le impostazioni selezionate, griglia

**PSEUDOCODICE**:
```C
griglia_gioco = griglia_scrivere_dimensione(griglia_gioco, impostazioni_leggere_dimensione_griglia(impostazioni_selezionate))
griglia_gioco = azzerare_griglia(griglia_gioco)
griglia_gioco = riempire_griglia(griglia_gioco, impostazioni_selezionate)
```
---
### FUNZIONE  riempire_griglia
**INPUT**:
- griglia_gioco, griglia da riempire, griglia
- impostazioni_utente, impostazioni scelte dall'utente, impostazioni

**OUTPUT**:
- griglia, griglia riempita con dei numeri inseriti in posizioni casuali, griglia

**DATI DI LAVORO**:
- coordinata_x, permette di selezionare una posizione casuale nella riga della griglia, numero naturale >0 <= DIMENSIONE_GRIGLIA_GRANDE
- coordinate_y, permette di selezionare una posizione casuale nella colonna della griglia, numero naturale >0 <= DIMENSIONE_GRIGLIA_GRANDE
- i, indice che permette di scorrere la griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
- numeri_da_inserire, numero di valori inseriti nella griglia, numero naturale >0 
- valore, valore da inserire all'interno della griglia, numero naturale >0 <= DIMENSIONE_GRIGLIA_GRANDE
- valore_griglia, valore della griglia che viene aggiornato mediante l'utilizzo di valore, valore_griglia

**PSEUDOCODICE**:
```C
i = 1

numeri_da_inserire = n_numeri_di_griglia(impostazioni_utente)

MENTRE(i <= numeri_da_inserire)
	coordinata_x = generare_n_casuale(1, griglia_leggere_dimensione(impostazioni_utente)) 
	coordinata_y = generare_n_casuale(1, griglia_leggere_dimensione(impostazioni_utente)) 
	SE(verificare_coordinate_e_valore(griglia, coordinate_x, coordinate_y) = VERO) 
		ALLORA valore = generare_n_casuale(1, leggere_dimensione_griglia(impostazioni_utente))
		SE(verificare_numero_da_inserire(griglia, valore, coordinata_x, coordinata_y)= VERO)
			ALLORA 
			valore_griglia = valore_griglia_scrivere_modificabile(valore_griglia, FALSO)
			valore_griglia = valore_griglia_scrivere_valore(valore_griglia, valore)
			griglia = griglia_scrivere_valore(griglia, coordinata_x, coordinata_y, valore_griglia)
			i = i + 1	
		FINE 			
	FINE
FINE
```