#include "gestire_controlli.h"

bool_t controllare_colonna(griglia griglia, int colonna, int numeri_da_inserire) {
  bool_t corretto;           //Indica se il numero può essere inserito o meno
  int i;
  int valore_cella;
  corretto = VERO;
  i = 0;
  while(i < griglia_leggere_dimensione(griglia)){
	  valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, colonna));
      if(valore_cella == numeri_da_inserire){
      	corretto = FALSO;
      }
      i = i + 1;
  }
	return corretto;
}

bool_t controllare_regione(griglia griglia, int riga, int colonna, int numero_da_inserire, int dimensione_regione) {
	bool_t corretto;
	int i;
	int j;
	int valore_cella;

	corretto = VERO;
	i = riga;
	while (i < riga + dimensione_regione) {
		j = colonna;
		while (j < colonna + dimensione_regione) {
			valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, i, j));
			if (valore_cella == numero_da_inserire) {
				corretto = FALSO;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return corretto;
}

bool_t controllare_riga(griglia griglia, int riga, int numero_da_inserire) {
	bool_t corretto;
	int j;
	int valore_cella;

	corretto = VERO;
	j = 0;
	while (j < griglia_leggere_dimensione(griglia)) {
		valore_cella = valore_griglia_leggere_valore(griglia_leggere_valore(griglia, riga, j));
		// Se il valore nella cella corrente è uguale al numero che vogliamo inserire,
		// allora il numero non può essere inserito in questa riga
		if (valore_cella == numero_da_inserire) {
				corretto = FALSO;
		}
		j = j + 1;
	}
	return corretto;
}

bool_t validare_colonna_input(int colonna, int dim_griglia) {
	bool_t validato;       //Indica se la colonna è valida o meno

	validato = VERO;
  if(colonna <= 0 || colonna > dim_griglia){
  	validato = FALSO;
  }
  return validato;
}

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

bool_t validare_riga_input(int riga, int dim_griglia) {
	bool_t validato;
	validato = VERO;
	if (riga <= 0 || riga > dim_griglia) {
		validato = FALSO;
	}
	return validato;
}

bool_t validare_valore_input(char valore, int dim_griglia) {
	int validato;
	int dim_griglia_carattere;

	validato = VERO;
	dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

	if(dim_griglia > DIM_GRIGLIA_GRANDE) {
		validato = FALSO;
	} else {
		if(dim_griglia <= DIM_GRIGLIA_GRANDE && (valore < CHAR_0 || (valore > CHAR_9 && valore < CHAR_A) || valore > dim_griglia_carattere))  {
			validato = FALSO;
		}
	}
	return validato;
}

bool_t verificare_coordinate_e_valore(griglia griglia_gioco, int coordinata_x, int coordinata_y) {
	bool_t valido;
	valido = VERO;

	if (valore_griglia_leggere_valore(griglia_leggere_valore(griglia_gioco, coordinata_x, coordinata_y)) != 0) {
		valido = FALSO;
	}
	return valido;
}

bool_t verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna) {
	bool_t corretto; //Sarà l'output della funzione ed è un booleano, permette di capire se il numero è già presente in riga, colonna, regione o meno
	int dimensione_griglia;//La seguente variabile verrà inizializzata con la dimensione della griglia
	int dimensione_regione;//Viene inizializzata con la dimensione della regione della griglia

	dimensione_griglia = griglia_leggere_dimensione(griglia);
	dimensione_regione = calcolare_radice_quadrata(dimensione_griglia);//La funzione calcolare_radice_quadrata permette di ottenere la dimensione esatta della regione
	corretto = FALSO;
	int inizio_regione_R = riga - calcolare_resto_intero(riga, dimensione_regione);
	int inizio_regione_C = colonna - calcolare_resto_intero(colonna, dimensione_regione);
	if (
		controllare_riga(griglia, riga, numero_da_inserire) == VERO   &&
		controllare_colonna(griglia, colonna, numero_da_inserire) == VERO &&
		controllare_regione(griglia, inizio_regione_R, inizio_regione_C, numero_da_inserire, dimensione_regione) == VERO
		) {
		corretto = VERO;
	}
	return corretto;
}

