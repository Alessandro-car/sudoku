#ifndef VALORE_GRIGLIA_H_
#define VALORE_GRIGLIA_H_

#include "../costanti.h"

typedef struct {
	int valore;
	bool_t modificabile;
} valore_griglia;

bool_t valore_griglia_leggere_modificabile(valore_griglia val);
int valore_griglia_leggere_valore(valore_griglia val);
void valore_griglia_scrivere_modificabile(valore_griglia* val, bool_t modificabile);
void valore_griglia_scrivere_valore(valore_griglia* val, int valore);

#endif
