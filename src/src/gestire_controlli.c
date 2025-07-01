#include "gestire_controlli.h"

/*	Funzione: controllare_colonna()
 * 	Descrizione: Questa funzione controlla se un numero può inserito inserito in una colonna data della griglia
 * 	Parametri:
 * 		-griglia, griglia nella quale controllare se il numero può essere inserito
 *		-colonna, colonna della griglia nella quale si vuole inserire il numero
 *		-numero_da_inserire, numero che si vuole inserire
 *	Dato di ritorno:
 *		-corretto, booleano che indica se il numero può essere inserito o meno
 */

bool_t controllare_colonna(griglia griglia, int colonna, int numero_da_inserire) {
  bool_t corretto;
  int i;			//Indice della riga della griglia
  int valore_cella; //Il valore della griglia nella riga 'i' e colonna 'colonna'
  corretto = VERO;
  i = 0;
  while(i < griglia_leggere_dimensione(griglia)){
	  valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, colonna));
      if(valore_cella == numero_da_inserire){ // Se nella colonna è presente almeno un valore uguale al numero da inserire allora l'esito è FALSO
      	corretto = FALSO;
      }
      i = i + 1;
  }
	return corretto;
}

/*	Funzione: controllare_regione()
 * 	Descrizione: Questa funzione controlla se un numero può inserito inserito in una regione data della griglia
 * 	Parametri:
 * 		-griglia, griglia nella quale controllare se il numero può essere inserito
 * 		-riga, riga della regione da controllare
 *		-colonna, colonna della regione da controllare
 *		-numero_da_inserire, numero che si vuole inserire
 *	Dato di ritorno:
 *		-corretto, booleano che indica se il numero può essere inserito o meno
 */

bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire) {
	bool_t corretto;
	int riga_inizio_regione;  	//Prima riga della regione
	int colonna_inizio_regione; //Prima colonna della regione
	int dimensione_regione; 	//Dimesione della regione della griglia
	int i; 						//Indice della riga della regione della griglia
	int j;						//Indice della colonna della regione della griglia
	int valore_cella;			//Il valore della griglia nella riga 'i' e colonna 'colonna

	dimensione_regione = calcolare_radice_quadrata(griglia_leggere_dimensione(griglia));
	riga_inizio_regione = riga - calcolare_resto_intero(riga, dimensione_regione);
	colonna_inizio_regione = colonna - calcolare_resto_intero(colonna, dimensione_regione);
	corretto = VERO;
	i = riga_inizio_regione;
	while (i < riga_inizio_regione + dimensione_regione) {
		j = colonna_inizio_regione;
		while (j < colonna_inizio_regione + dimensione_regione) {
			valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, j));
			if (valore_cella == numero_da_inserire) { //Se nella regione è presente almeno un valore uguale al numero da inserire allora l'esito è FALSO
				corretto = FALSO;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return corretto;
}

/*	Funzione: controllare_riga()
 * 	Descrizione: Questa funzione controlla se un numero può inserito inserito in una riga data della griglia
 * 	Parametri:
 * 		-griglia, griglia nella quale controllare se il numero può essere inserito
 * 		-riga, riga nella quale si vuole inserire il numero
 *		-numero_da_inserire, numero che si vuole inserire
 * 	Dato di ritorno:
 *		-corretto, booleano che indica se il numero può essere inserito o meno
 */
bool_t controllare_riga(griglia griglia, int riga, int numero_da_inserire) {
	bool_t corretto;
	int j;				//Indice della colonna della griglia
	int valore_cella;  //Il valore della griglia nella riga 'riga' e colonna 'j'

	corretto = VERO;
	j = 0;
	while (j < griglia_leggere_dimensione(griglia)) {
		valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, riga, j));
		if (valore_cella == numero_da_inserire) { //Se nella griglia è presente almeno un valore uguale al numero da inserire allora l'esito è FALSO
				corretto = FALSO;
		}
		j = j + 1;
	}
	return corretto;
}

/*	Funzione: validare_colonna_input()
 * 	Descrizione: Questa funzione controlla se l'utente ha inserito un valore della colonna valido
 * 	Parametri:
 * 		-colonna, valore della colonna inserito dall'utente
 * 		-dim_griglia, dimensione della griglia
 *	Dato di ritorno:
 *		-validato, booleano che indica se il numero di colonna inserito è valido o meno
 */
bool_t validare_colonna_input(int colonna, int dim_griglia) {
	bool_t validato;

	validato = VERO;
  if(colonna <= 0 || colonna > dim_griglia) { //Se il valore di colonna non è nell'intervallo [1, dim_griglia] allora l'esito è FALSO
  	validato = FALSO;
  }
  return validato;
}

/*	Funzione: validare_input_utente()
 * 	Descrizione: Questa funzione controlla se l'utente ha inserito dei valori di riga, colonna e valore
 * 	Parametri:
 * 		-colonna, valore della colonna inserito dall'utente
 * 		-dim_griglia, dimensione della griglia
 *	Dato di ritorno:
 *		-validato, booleano che indica se il numero di colonna inserito è valido o meno
 */
bool_t validare_input_utente(int riga, int colonna, char valore, griglia griglia_gioco){
	bool_t validato;
	int dim_griglia;
	validato = FALSO;
	dim_griglia = griglia_leggere_dimensione(griglia_gioco);
	valore = convertire_minuscolo_maiuscolo(valore);

	if (validare_riga_input(riga, dim_griglia) == VERO &&
		validare_colonna_input(colonna, dim_griglia) == VERO &&
		validare_valore_input(valore, dim_griglia) == VERO) {
		validato = VERO;
	}

	return validato;
}

/*	Funzione: validare_riga_input()
 * 	Descrizione: Questa funzione controlla se l'utente ha inserito un valore della riga valido
 * 	Parametri:
 * 		-colonna, valore della riga inserito dall'utente
 * 		-dim_griglia, dimensione della griglia
 *	Dato di ritorno:
 *		-validato, booleano che indica se il numero di riga inserito è valido o meno
 */
bool_t validare_riga_input(int riga, int dim_griglia) {
	bool_t validato;
	validato = VERO;
	if (riga <= 0 || riga > dim_griglia) { //Se il valore della griglia non è nell'intervallo [1, riga] allora l'esito è FALSO
		validato = FALSO;
	}
	return validato;
}

/*	Funzione: validare_valore_input()
 * 	Descrizione: Questa funzione controlla se l'utente ha inserito un valore del valore della griglia valido
 * 	Parametri:
 * 		-colonna, valore del valore della griglia inserito dall'utente
 * 		-dim_griglia, dimensione della griglia
 *	Dato di ritorno:
 *		-validato, booleano che indica se il numero del valore inserito è valido o meno
 */
bool_t validare_valore_input(char valore, int dim_griglia) {
	int validato;
	char dim_griglia_carattere;  //Valore in lettera della dimensione della griglia

	validato = VERO;
	dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

	//Se il valore non è nell'intervallo [0, dim_griglia_carattere] allora l'esito è FALSO
	if(valore < CHAR_0 || (valore > CHAR_9 && valore < CHAR_A) || valore > dim_griglia_carattere) {
		validato = FALSO;
	}
	return validato;
}

/*	Funzione: verificare_coordinate()
 * 	Descrizione: Questa funzione controlla la cella della griglia nelle coordinate date è vuota
 * 	Parametri:
 * 		-griglia, griglia di gioco
 * 		-coordinata_x, riga della cella della griglia da controllare
 * 		-coordinata_y, colonna della cella della griglia da controllare
 *	Dato di ritorno:
 *		-valido, booleano che indica se la cella è vuota o meno
 */
bool_t verificare_coordinate(griglia griglia_gioco, int coordinata_x, int coordinata_y) {
	bool_t valido;
	valido = VERO;

	//Se il valore della griglia nelle coordinate date è diverso da 0 allora la cella è piena e quindi l'esito è FALSO
	if (valore_griglia_leggere_valore(griglia_leggere_valore(griglia_gioco, coordinata_x, coordinata_y)) != 0) {
		valido = FALSO;
	}
	return valido;
}

/*	Funzione: verificare_numero_da_inserire()
 * 	Descrizione: Questa funzione controlla se un numero dato può essere inserito nella griglia nelle coordinate date
 * 	Parametri:
 * 		-griglia, griglia di gioco
 * 		-numero_da_inserire, numero che si vuole inserire nella griglia
 * 		-riga, riga della griglia nella quale si vuole inserire il numero
 * 		-colonna, colonna della griglia nella quale inserire il numero
 *	Dato di ritorno:
 *		-corretto, booleano che indica se il numero può essere inserito o meno
 */
bool_t verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna) {
	bool_t corretto;
	corretto = FALSO;
	if (
		controllare_riga(griglia, riga, numero_da_inserire) == VERO   &&
		controllare_colonna(griglia, colonna, numero_da_inserire) == VERO &&
		controllare_regione(griglia, riga, colonna, numero_da_inserire) == VERO
		) {
		corretto = VERO;
	}
	return corretto;
}

