valore_griglia:
- modificabile, valore booleano che permette di capire se un valore è modificabile, booleano
- valore, valore presente all'interno della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE
---
### FUNZIONI DI ACCESSO:
valore_griglia_leggere_modificabile; valore_griglia_scrivere_modificabile; valore_griglia_leggere_valore; valore_griglia_scrivere_valore

---
##### valore_griglia_leggere_modificabile
**INPUT**:
- valore_griglia, valore della griglia al cui interno leggere se è modificabile o meno, valore_griglia

**OUTPUT**:
- modificabile, booleano che permette di capire se il valore è modificabile o meno, booleano

**PSEUDOCODICE**:
```C
modificabile = campo modificabile di valore_griglia
```
---
##### valore_griglia_leggere_valore
**INPUT**:
- valore_griglia, valore della griglia al cui interno è presente il valore da leggere, valore_griglia

**OUTPUT**:
- valore, valore letto, numero naturale > 0 <= DIM_GRIGLIA_GRANDE

**PSEUDOCODICE**:
```C
valore = campo valore di valore_griglia
```
---
##### valore_griglia_scrivere_valore
**INPUT**:
- valore_griglia, valore della griglia al cui interno verrà scritto il valore, valore_griglia
- valore, valore da scrivere all'interno della griglia, numero naturale >0 <= DIM_GRIGLIA_GRANDE

**OUTPUT**:
- valore_griglia, valore della griglia al cui interno è presente il valore scritto, valore_griglia


**PSEUDOCODICE**:
```C
valore = campo valore di valore_griglia
```
---
##### valore_griglia_scrivere_modificabile
**INPUT**:
- valore_griglia, valore della griglia al cui interno scrivere il modidficabile, valore_griglia
- modificabie, booleano che verrà scritto in valore_griglia, booleano

**OUTPUT**:
- valore_griglia, valore della griglia al cui interno è presente modificabile, valore_griglia

**PSEUDOCODICE**:
```C
campo modificabile di valore_griglia = modificabile
```