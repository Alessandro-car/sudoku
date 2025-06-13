#include "gestire_griglia_gioco.h"
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "gestire_partita.h"
#include "gestire_griglia_gioco.h"

griglia riempire_griglia(impostazioni impostazioni_utente){
    griglia griglia;            //Griglia prodotta secondo le impostazioni
    int numeri_da_inserire;     //Rappresenta il numero di elementi che verrano inseriri in griglia
    int coordinata_x;           //Rappresenta una posizione casuale tra le righe
    int coordinata_y;           //Rappresenta una posizione casuale tra le colonne
    int valore;                 //Rappresenta il valore che verrà inserito nella griglia

    int i;

    i = 0;
    srand(time(NULL));          //Serve per la funzione rand, se non si mette rand utilizza sempre la stessa sequenza di numeri
    numeri_da_inserire = n_numeri_di_griglia(impostazioni_utente);

    while(i < numeri_da_inserire){
        coordinata_x = rand() % impostazioni_leggere_dimensione_griglia(impostazioni_utente) + 1;
        coordinata_y = rand() % impostazioni_leggere_dimensione_griglia(impostazioni_utente) + 1;
        if(verificare_coordinate_e_valore(coordinata_x, coordinata_y) == 1){
            valore = rand() % impostazioni_leggere_dimensione_griglia(impostazioni_utente) + 1;
            if(verificare_numero_da_inserire(griglia, valore, coordinata_x, coordinata_y) == 1){
                if(valore < 9){
                    griglia_scrivere_valore(&griglia, coordinata_x, coordinata_y, valore);
                }else{
                    valore = convertire_numeri_in_lettere(valore);
                    griglia_scrivere_valore(&griglia, coordinata_x, coordinata_y, valore);
                }
            }
        }
        i = i + 1;
    }
    return griglia;
}

