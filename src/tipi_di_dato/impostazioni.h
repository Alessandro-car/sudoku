#ifndef IMPOSTAZIONI_H_
#define IMPOSTAZIONI_H_

typedef struct {
	int dimensione_griglia;
	int difficolta;
} impostazioni;

int impostazioni_leggere_difficolta(impostazioni impostazioni_partita);
int impostazioni_leggere_dimensione_griglia(impostazioni impostazioni_partita);
void impostazioni_scrivere_difficolta(impostazioni* impostazioni_partita, int nuova_difficolta);
void impostazioni_scrivere_dimensione_griglia(impostazioni* impostazioni_partita, int nuova_dimensione);

#endif


