Partita:
- impostazioni_partita, impostazioni della partita, impostazioni
- griglia_partita, griglia della partita, griglia
- nome_partita, indica il nome della partita, stringa

### FUNZIONI DI ACCESSO:
partita_leggere_impostazioni; partita_scrivere_impostazioni; partita_leggere_griglia; partita_scrivere_griglia; partita_leggere_nome; partita_scrivere_nome

---
##### partita_leggere_impostazioni
**INPUT**:
- partita, partita da cui leggere impostazioni_partita, partita

**OUTPUT**:
- impostazioni_lette, impostazioni della partita lette, impostazioni

**PSEUDOCODICE**:
```C
impostazioni_lette = campo impostazioni_partita di partita
```
---
##### partita_scrivere_impostazioni
**INPUT**:
- partita, partita in cui scrivere le impostazioni, partita
- impostazioni_modificate, impostazioni che andranno scritte all'interno di partita, impostazioni

**OUTPUT**:
- partita, partita con le impostazioni modificate, partita

**PSEUDOCODICE**:
```C
campo impostazioni_partita di partita = impostazioni_modificate
```
---
##### partita_leggere_griglia
**INPUT**:
- partita, partita da cui leggere griglia_partita, partita

**OUTPUT**:
- griglia_letta, griglia che verrà letta, griglia

**PSEUDOCODICE**:
```C
griglia_letta = campo griglia_partita di partita
```
---
##### partita_scrivere_griglia
**INPUT**:
- partita, partita in cui scrivere griglia_partita, partita
- griglia_modificata, griglia modificata, griglia

**OUTPUT**:
- partita, partita con la griglia modificata al suo interno, partita

**PSEUDOCODICE**:
```C
campo griglia_partita di partita = griglia_modificata
```
---
##### partita_leggere_nome
**INPUT**:
- partita, partita da cui leggere nome_partita, partita

**OUTPUT**:
- nome_partita_letto, nome della partita letto, stringa

**PSEUDOCODICE**:
```C
nome_partita_letta = campo nome_partita di partita
```
---
##### partita_scrivere_nome
**INPUT**:
- partita, partita in cui scrivere nome_partita, partita
- nome_partita_modificato, nuovo nome della partita che verrà inserito all'interno della partita, stringa

**OUTPUT**:
- partita, partita con nome_partita_modificato al suo interno, partita

**PSEUDOCODICE**:
```C
campo nome_partita di partita = nome_partita_modificato
```