#include "utils.h"

int convertire_lettera_in_numero(char lettera) {
		int numero;
		numero = -1;

		if (lettera >= 'A' && lettera <= 'G') {
			numero = lettera - 55;
		} else if (lettera >= '0' && lettera <= '9') {
			numero = lettera - 48;
		}
		return numero;
}

char convertire_numeri_in_lettere(int numero) {

	char lettera;

	lettera = ' ';
	if(numero >= 10 && numero<= DIMENSIONE_GRIGLIA_GRANDE) {
		lettera = numero + 55;
	}
	if(numero >= 0 && numero <= 9){
		lettera = numero + 48;
	}
	return lettera;
}
