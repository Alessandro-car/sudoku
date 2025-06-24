#include "gestire_errori.h"

void stampare_banner_errore(int x, int y, int dim, char* messaggio_errore) {
	int i;
	i = 1;
	while (i < dim - 2) {
		impostare_coordinate_cursore(x + i, y - 1);
		printf("-");
		i = i + 1;
	}

	impostare_coordinate_cursore(x + 1, y);
	stampare_centrato_colorato(COLORE_ANSI_ROSSO, messaggio_errore, dim);

}


