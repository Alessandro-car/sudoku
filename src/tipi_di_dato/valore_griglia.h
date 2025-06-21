#ifndef TIPI_DI_DATO_VALORE_GRIGLIA_H_
#define TIPI_DI_DATO_VALORE_GRIGLIA_H_

#include "../utils.h"

typedef struct {
	int valore;
	bool_t modificabile;
} valore_griglia;

int valore_griglia_leggere_valore(valore_griglia val);
bool_t valore_griglia_leggere_modificabile(valore_griglia val);
void valore_griglia_scrivere_valore(valore_griglia* val, int valore);
void valore_griglia_scrivere_modificabile(valore_griglia* val, bool_t modificabile);

#endif
