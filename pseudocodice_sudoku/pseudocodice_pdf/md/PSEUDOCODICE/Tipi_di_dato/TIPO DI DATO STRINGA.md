stringa:
- dimensione, dimensione della stringa, numero naturale > 0 AND <= DIMENSIONE_MAX_STRINGA
- caratteri, caratteri della stringa, array di caratteri 

### FUNZIONI DI ACCESSO:
stringa_leggere_dimensione; stringa_scrivere_dimensione; stringa_leggere_carattere; stringa_scrivere_carattere; stringa_leggere_array; stringa_scrivere_array

---
##### stringa_leggere_dimensione
**INPUT**:
- stringa, stringa da cui leggere la dimensione, stringa

**OUTPUT**:
- dimensione_letta, dimensione letta presente dentro stringa, numero naturale > 0 AND <= DIMENSIONE_MAX_STRINGA

**PSEUDOCODICE**:
```C
dimensione_letta = campo dimensione di stringa
```
---
##### stringa_scrivere_dimensione
**INPUT**:
- stringa, stringa in cui scrivere la dimensione, stringa
- nuova_dimensione, dimensione presente in stringa che verra' modificata,  numero naturale > 0 AND <= DIMENSIONE_MAX_STRINGA

**OUTPUT**:
- stringa, stringa con al suo interno nuova_dimensione, stringa

**PSEUDOCODICE**:
```C
campo dimensione di stringa = dimensione_modificata
```
---
##### stringa_leggere_carattere
**INPUT**:
- stringa, stringa da cui leggere i caratteri, stringa
- pos, posizione del carattere da leggere, numero naturale >0

**OUTPUT**:
- carattere_letto, carattere lette, carattere

**PSEUDOCODICE**:
```C
carattere_letto = campo carattere in posizione pos di stringa
```
---
##### stringa_scrivere_carattere
**INPUT**:
- stringa, stringa in cui scrivere il carattere, stringa
- pos, posizione del carattere scritto, numero naturale > 0
- carattere, carattere da scrivere, carattere

**OUTPUT**:
- stringa, stringa con il carattere modificato, stringa

**PSEUDOCODICE**:
```C
campo carattere in posizione pos di stringa = carattere
```
---
##### stringa_leggere_array
**INPUT**:
- stringa, stringa con al suo interno l'array da leggere, stringa

**OUTPUT**:
- stringa_letta, stringa letta, array di caratteri
  
**DATI DI LAVORO:**
- i, indice della stringa, numero naturale > 0 <= DIM_MAX_STRINGA
- dim_stringa, rappresenta la dimensione della stringa, numero naturale > 0 <= DIM_MAX_STRINGA

**PSEUDOCODICE**:
```C
dim_stringa = stringa_leggere_dimensione(stringa) 
i = 1 
MENTRE(i <= dim_stringa) 
	stringa_letta in posizione i = stringa_leggere_carattere(stringa, i) 
	i = i + 1
FINE 
stringa_letta in posizione i = '\0'
```
---
##### stringa_scrivere_array
**INPUT**:
- stringa, stringa in cui scrivere l'array, stringa
- caratteri, caratteri che verranno scritti all'interno di stringa, array di caratteri
- dim_stringa, dimensione della stringa, numero naturale >0 <= DIM_MAX_STRINGA

**OUTPUT**:
- stringa, stringa modificata, stringa
  
**DATI DI LAVORO:**
- i, indice che scorre la stringa, numero naturale > 0 <= DIM_MAX_STRINGA

**PSEUDOCODICE**:
```C
stringa = stringa_scrivere_dimensione(stringa, dim_stringa)
MENTRE(i <= dim_stringa) 
	stringa = stringa_scrivere_carattere(stringa, i, i'esimo arattere di caratteri) 
	i = i + 1 
FINE
```