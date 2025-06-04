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
