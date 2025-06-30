impostazioni:
- dimensione_griglia, indica la dimensione della griglia, numero naturale > 0 <= DIM_GRIGLIA_GRANDE
- difficolta, indica la difficoltà del gioco, numero naturale $\in$ \[1,3]

### FUNZIONI DI ACCESSO:
impostazioni_leggere_dimensione_griglia; impostazioni_scrivere_dimensione_griglia; impostazioni_leggere_difficolta; impostazioni_scrivere_difficolta

---
##### impostazioni_leggere_dimensione_griglia
**INPUT**:
- impostazioni_partita, impostazioni dalle quali leggere la dimensione della griglia, impostazioni

**OUTPUT**:
- dimensione_griglia, dimensione letta di impostazioni, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
dimensione_griglia = campo dimensione_griglia di impostazioni_partita
```
---
##### impostazioni_scrivere_dimensione_griglia
**INPUT**:
-impostazioni_partita, impostazioni in cui scrivere la dimensione della griglia, impostazioni
-dimensione_griglia, nuova dimensione da assegnare alla griglia, numero naturale > 0 <= DIM_GRIGLIA GRANDE

**OUTPUT**:
- impostazioni_partita, impostazioni con la dimensione griglia modificata, impostazioni

**PSEUDOCODICE**:
```C
campo dimensione_griglia di impostazioni_partita = dimensione_griglia
```
---
##### impostazioni_leggere_difficolta
**INPUT**:
- impostazioni_partita, impostazioni dalle quali leggere la difficoltà, impostazioni

**OUTPUT**:
- livello_difficolta, difficoltà letta da impostazioni_partita, numero naturale $\in$ \[1,3]

**PSEUDOCODICE**:
```C
livello_difficolta = campo difficolta di impostazioni_partita
```
---
##### impostazioni_scrivere_difficolta
**INPUT**:
- impostazioni_partita, impostazioni in cui scrivere la difficoltà, impostazioni
- nuova_difficolta, nuova difficoltà scelta, numero naturale ∈ \[1,3]

**OUTPUT**:
- impostazioni_partita, impostazioni con la difficoltà modificata, impostazioni

**PSEUDOCODICE**:
```C
campo difficolta di impostazioni_partita = nuova_difficolta
```