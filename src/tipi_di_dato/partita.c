#include "partita.h"

griglia partita_leggere_griglia(partita var_partita) {
	griglia griglia_partita;
	griglia_partita = var_partita.griglia_partita;
	return griglia_partita;
}

impostazioni partita_leggere_impostazioni(partita var_partita) {
	impostazioni impostazioni_lette;
	impostazioni_lette = var_partita.impostazioni_partita;
	return impostazioni_lette;
}

stringa partita_leggere_nome(partita var_partita) {
	stringa nome_partita;
	nome_partita = var_partita.nome_partita;
	return nome_partita;
}


void partita_scrivere_griglia(partita* var_partita, griglia nuova_griglia) {
	var_partita->griglia_partita = nuova_griglia;
	return;
}

void partita_scrivere_impostazioni(partita* var_partita, impostazioni nuove_impostazioni) {
	var_partita->impostazioni_partita = nuove_impostazioni;
	return;
}

void partita_scrivere_nome(partita *var_partita, stringa nuovo_nome) {
	var_partita->nome_partita = nuovo_nome;
	return;
}
