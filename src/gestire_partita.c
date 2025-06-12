#include "gestire_partita.h"


int validare_valore_input(int valore, int dim_griglia) {
//La seguente funzione permette di verificare se un valore inserito dall'utente può venir considerato valido
int validato; //booleano che che varrà come output
int dim_griglia_carattere;

validato = 1; //Booleano inizializzato a VERO
dim_griglia_carattere = convertire_numeri_in_lettere(dim_griglia);

if(dim_griglia >= 16 && (valore < 48 || (valore > 57 && valore < 65) || valore > dim_griglia_carattere )) { /*verifica che non  si vada incontro
ai vincoli sulla dim_griglia e sul valore*/
*/
	validato = 0; //Nel caso allora validato = FALSO
} else {
	if(dim_griglia < 16 && (valore < 48 || valore >57))  {/*verifica che non  si vada incontro
ai vincoli sulla dim_griglia e sul valore*/
		validato = 0;
	}
}
	return validato;
}

int verificare_numero_da_inserire(griglia griglia, int numero_da_inserire, int riga, int colonna) {
//La seguente funzione permette di verificare se è stato inserito un numero in una "cella" non valida, effettuando controlli su riga, colonna e regione

	int corretto; //Sarà l'output della funzione ed è un booleano, permette di capire se il numero è già presente in riga, colonna, regione o meno
	int i; //Permette di scorrere la griglia
	int j; //Permette di scorrere la griglia
	int dimensione_griglia;//La seguente variabile verrà inizializzata con la dimensione della griglia
	int dimensione_regione;//Viene inizializzata con la dimensione della regione della griglia

	dimensione_griglia = griglia_leggere_dimensione(griglia);
	dimensione_regione = calcolare_radice_quadrata(dimensione_griglia);//La funzione calcolare_radice_quadrata permette di ottenere la dimensione esatta della regione
	corretto = controllare_riga(griglia, riga, numero_da_inserire, dimensione_griglia); //Inizializza corretto con la funzione controllare_riga che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa riga

	if(corretto == 1) {//Se il primo controllo è andato a buon fine allora passa al controllo della colonna
		corretto = controllare_colonna(griglia, colonna, numero_da_inserire, dimensione_griglia); //Imposta corretto con la funzione controllare_colonna che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa colonna
	}
	if(corretto == 1) {//Se il secondo controllo è andato a buon fine passa al controllo sulla regione
		riga = riga - calcolare_resto_intero(riga, dimensione_regione);//Permette di ottenere la dimensione della riga della regione
		colonna =  colonna - calcolare_resto_intero(colonna, dimensione_regione); //Permette di ottenere la dimensione della colonna della regione
		corretto = controllare_regione(griglia, riga, colonna, numero_da_inserire, dimensione_regione);//Imposta corretto con la funzione controllare_regione che ha come output booleano, che sarà VERO se non ci sono valori uguali nella stessa regione
	}
	return corretto;
}


