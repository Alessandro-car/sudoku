#include "valore_griglia.h"

int valore_griglia_leggere_valore(valore_griglia val) {
	int valore;
	valore = val.valore;
	return valore;

}
bool_t valore_griglia_leggere_modificabile(valore_griglia val) {
	bool_t modificabile;
	modificabile = val.modificabile;
	return modificabile;
}
void valore_griglia_scrivere_valore(valore_griglia* val, int valore) {
	val->valore = valore;
	return;
}

void valore_griglia_scrivere_modificabile(valore_griglia* val, bool_t modificabile) {
	val->modificabile = modificabile;
	return;
}



