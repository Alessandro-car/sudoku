griglia:
- dimensione_griglia, indica la dimensione della griglia, tipo numero naturale > 0 AND <= DIM_GRIGLIA_GRANDE
- valore_griglia, contiene i valori della griglia, valore_griglia
### FUNZIONI DI ACCESSO:
griglia_leggere_dimensione; griglia_scrivere_dimensione; griglia_leggere_valore; griglia_scrivere_valore

---
##### griglia_leggere_dimensione
**INPUT**:
- griglia, griglia dalla quale  leggere la dimensione, griglia

**OUTPUT**:
- dimensione, dimensione letta di griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
dimensione = campo dimensione_griglia di griglia
```
---
##### griglia_scrivere_dimensione
**INPUT**:
- griglia, griglia in cui scrivere la dimensione, griglia
- nuova_dimensione, nuova dimensione da assegnare alla griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- griglia, griglia con la dimensione modificata, griglia

**PSEUDOCODICE**:
```C
campo dimensione_griglia di griglia = nuova_dimensione
```
---
##### griglia_leggere_valore
**INPUT**:
- griglia_partita, griglia dalla quale leggere il valore, griglia
- riga, riga nella quale si trova il valore da leggere, numero naturale > 0 AND <= DIM_GRIGLIA_GRANDE
- colonna, colonna nella quale si trova il valore da leggere, numero naturale > 0 AND <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- valore_letto, valore letto nella griglia, valore_griglia

**PSEUDOCODICE**:
```C
valore_letto = campo valore_griglia in posizione riga e colonna di griglia_partita
```
---
##### griglia_leggere_valore
**INPUT**:
- griglia_partita, griglia in cui scrivere il valore, griglia
- valore, valore da inserire nella griglia, valore_griglia
- riga, riga nella quale inserire il valore, numero naturale > 0 AND <= DIM_GRIGLIA_GRANDE
- colonna, colonna nella quale inserire il valore, numero naturale > 0 DIM_GRIGLIA_GRANDE

**OUTPUT**:
- griglia_partita, griglia con il valore modifcato, griglia

**PSEUDOCODICE**:
```C
campo valore_griglia in posizione riga e colonna di griglia _partita = valore
```
