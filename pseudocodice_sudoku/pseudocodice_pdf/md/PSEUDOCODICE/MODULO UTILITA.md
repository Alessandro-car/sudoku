all'interno del seguente modulo sono presenti in totale 9 funzioni, ovvero: 
controllare_caratteri_stringa; concatenare_due_stringhe; calcolare_dimensione_array; controllare_caratteri_stringa; convertire_minuscolo_maiuscolo; convertire_numeri_in_lettere; calcolare_radice_quadrata; calcolare_resto_intero; convertire_lettera_in_numero

---
### FUNZIONE  controllare_caratteri_stringa
**INPUT**:
- str, stringa di cui controllare i caratteri, stringa

**OUTPUT**:
- caratteri_da_controllare, caratteri da controllare, array di caratteri

**DATI DI LAVORO**:
- i, indice per scorrere str, numero naturale > 0 
- j, indice per scorrere caratteri_da_controllare, numero naturale > 0

**PSEUDOCODICE**:
```C
i = 1

MENTRE(i <= stringa_leggere_dimensione(caratteri_da_controllare) AND esito = FALSO)
	j = 1 
	MENTRE(j <= stringa_leggere_dimensione(str) AND esito <> FALSO)
		SE(stringa_leggere_carattere(str, j) = i'esima posizione di caratteri_da_controllare + i)	
			ALLORA esito = FALSO
		FINE
		j = j + 1
	FINE
	i = i + 1
FINE
```
---
### FUNZIONE  concatenare_due_stringhe
**INPUT**:
- str1, caratteri da concatenare, array di caratteri
- str2, caratteri da concatenare, array di caratteri

**OUTPUT**:
- stringa_finale, stringa finale nata dalla concatenazione delle prime due, array di caratteri

**DATI DI LAVORO**:
- dimensione1, dimensione di str1, numero naturale > 0
- dimensione2, dimensione di str2, numero naturale > 0
- i, indice per scorrere le dimensioni, numero naturale > 0
- dimensione_stringa_finale, rappresenta la dimensione della stringa finale, numero naturale >0

**PSEUDOCODICE**:
```C
i = 1
j = 1

dimensione1 = calcolare_dimensione_array(str1)
dimensione2 = calcolare_dimensione_array(str2)

dimensione_stringa_finale = dimensione1 + dimensione2

MENTRE(i <= dimensione_stringa_finale)
	i'esimo elemento di stringa_finale = i'esimo elemento di str1
	i = i + 1
FINE
i = dimensione1 + 1
MENTRE(i <= dimensione_stringa_finale)
	i'esimo elemento di stringa_finale = j'esimo elemento di str2
	i = i + 1
	j = j + 1
FINE
```
---
### FUNZIONE  calcolare_dimensione_array
**INPUT**:
- caratteri, insieme di caratteri, array di caratteri

**OUTPUT**:
- dimensione, dimensione dell'array, numero naturale > 0

**DATI DI LAVORO**:
- i, indice per scorrere caratteri, numero naturale > 0

**PSEUDOCODICE**:
```C
i = 1
MENTRE(i'esimo elemento di caratteri <> '\0')
	dimensione = dimensione + 1
	i = i + 1
FINE
```
---
### FUNZIONE  convertire_minuscolo_maiuscolo
**INPUT**:
- lettera, lettera da convertire dal minuscolo al maiuscolo, carattere

**OUTPUT**:
- lettera_convertita, lettera convertita da minuscolo a maiuscolo, carattere

**PSEUDOCODICE**:
```C
lettera_convertita = lettera
SE ((lettera_convertita >= CHAR_a) AND (lettera_convertita <= CHAR_z))
	ALLORA lettera_convertita = lettera - 32
FINE
```
---
### FUNZIONE  convertire_numeri_in_lettere
**INPUT**:
- numero, numero che  verrà convertito in lettera, numero naturale >0 

**OUTPUT**:
- lettera, lettera che rappresenta il numero convertito, carattere

**PSEUDOCODICE**:
```C
lettera = ' '
SE(numero >= 10 && numero <= DIM_GRIGLIA_GRANDE)
	ALLORA	lettera = numero + 55
	ALTRIMENTI 
		SE(numero >= 0 && numero <= 9)
			ALLORA lettera = numero + 48		
		FINE 
FINE	
```
---
### FUNZIONE  calcolare_radice_quadrata
**INPUT**:
- radicando, numero da operare con la radice, numero naturale 

**OUTPUT**:
- radice, risultato dell' operazione, numero numero intero 

**DATI DI LAVORO**:
- radice_quad, numero che rappresenta la radice quadrata, numero intero
- trovato, valore booleano, booleano

**PSEUDOCODICE**:
```C
trovato = FALSO
radice = 2
radice_quad = radice * radice
MENTRE(radicando >= radice_quad AND trovato = FALSO)
	SE(radice_quad = radicando)
		ALLORA
			trovato = VERO
			radice = radice - 1
	FINE
	radice = radice + 1
	radice_quad = radice * radice
FINE
SE(trovato = FALSO)
	ALLORA radice = 0
FINE
```
---
### FUNZIONE  calcolare_resto_intero
**INPUT**:
- numeratore, numeratore dell'operazione, numero naturale
- denominatore, denominatore dell'operazione, numero naturale

**OUTPUT**:
- risultato, resto della divisione, numero intero

**PSEUDOCODICE**:
```C
MENTRE(numeratore >= denominatore)
	numeratore = numeratore - denominatore
FINE
```
---
### FUNZIONE  convertire_lettera_in_numero
**INPUT**:
- lettera, lettera che  verrà convertita in numero, carattere

**OUTPUT**:
- numero, numero che rappresenta la lettera convertita, numero naturale > 0

**PSEUDOCODICE**:
```C
SE(lettera >= CHAR_A AND lettera <= CHAR_G)
	ALLORA numero = lettera - 55
	ALTRIMENTI 
		SE(lettera >= CHAR_0 AND lettera <= CHAR_9) 
			ALLORA numero = lettera - 48
	   	FINE	
FINE 
```