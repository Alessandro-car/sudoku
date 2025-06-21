#ifndef COORDINATA_H_
#define COORDINATA_H_

typedef struct {
	int riga;
	int colonna;
} coordinata;

int coordinata_leggere_riga(coordinata coord);
void coordinata_scrivere_riga(coordinata *coord, int riga);
int coordinata_leggere_colonna(coordinata coord);
void coordinata_scrivere_colonna(coordinata *coord, int colonna);

#endif
