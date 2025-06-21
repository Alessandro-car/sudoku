#include "coordinata.h"


int coordinata_leggere_riga(coordinata coord) {
	int riga;
	riga = coord.riga;
	return riga;
}

void coordinata_scrivere_riga(coordinata *coord, int riga) {
	coord->riga = riga;
	return;
}

int coordinata_leggere_colonna(coordinata coord) {
	int colonna;
	colonna = coord.colonna;
	return colonna;
}

void coordinata_scrivere_colonna(coordinata *coord, int colonna) {
	coord->colonna = colonna;
	return;
}

