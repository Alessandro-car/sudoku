file_binario:
- elemento, elementi presenti nel file, record
- posizione, posizione del file, numero naturale
- nome_file, nome del file, stringa

### FUNZIONI DI ACCESSO:
leggere_posizione; leggere_elemento; scrivere_posizione; scrivere_elemento; leggere_nome_file; scrivere_nome_file

---
##### leggere_posizione
**INPUT**:
- file, file dal quale  leggere la posizione, file_binario

**OUTPUT**:
- posizione, posizione del file, numero naturale

**PSEUDOCODICE**:
```C
posizione = campo posizione di file
```
---
##### leggere_elemento
**INPUT**:
- file, file dal quale leggere un record, le_binario

**OUTPUT**:
- record, record letto dal file, record

**PSEUDOCODICE**:
```C
record = campo elemento in posizione leggere_posizione(file) di file
file = scrivere_posizione(file)
```
---
##### scrivere_elemento
**INPUT**:
- file, file in cui scrivere un record, file_binario
- record, record da scrivere nel file, record

**OUTPUT**:
- file, file con il record inserito, file_binario

**PSEUDOCODICE**:
```C
campo elemento in posizione leggere_posizione(file) di file = record
file = scrivere_posizione(file)
```
---
##### scrivere_posizione
**INPUT**:
- file, file in cui scrivere la posizione, file_binario

**OUTPUT**:
- file, file di testo a cui è stato cambiato il valore della posizione, file_binario

**PSEUDOCODICE**:
```C
campo posizione di file = campo posizione di f + 1
```
---
##### leggere_nome_file
**INPUT**:
- file, file  dal quale leggere nome_file, file_binario

**OUTPUT**:
- nome_file_letto, nome del file letto, stringa

**PSEUDOCODICE**:
```C
nome_file_letto = campo nome_file di file
```
---
##### scrivere_nome_file
**INPUT**:
- file, file in cui scrivere nome_file, file_binario
- nome_file_modificato, nome da scrivere nel file, stringa

**OUTPUT**:
- file, file con al suo interno nome_file_modificato, file_binario

**PSEUDOCODICE**:
```C
campo nome_file di file = nome_file_modificato
```