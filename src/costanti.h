#ifndef COSTANTI_H_
#define COSTANTI_H_

#define COLORE_ANSI_BIANCO "\x1b[37m"
#define COLORE_ANSI_BLU "\x1b[34m"
#define COLORE_ANSI_CIANO "\x1b[36m"
#define COLORE_ANSI_GIALLO "\x1b[33m"
#define COLORE_ANSI_MAGENTA "\x1b[35m"
#define COLORE_ANSI_NERO "\x1b[30m"
#define COLORE_ANSI_RESET "\x1b[m"
#define COLORE_ANSI_ROSSO "\x1b[91m"
#define COLORE_ANSI_VERDE "\x1b[32m"
#define CODICE_ANSI_GRASSETTO "\x1b[1m"

#define DIM_GRIGLIA_PICCOLA 4
#define DIM_GRIGLIA_STANDARD 9
#define DIM_GRIGLIA_GRANDE 16

#define DIFFICOLTA_STANDARD 0
#define DIFFICOLTA_MEDIA 1
#define DIFFICOLTA_DIFFICILE 2

#define MAX_PARTITE_SALVATE 5

#define DIM_MAX_STRINGA 20

#define PERCENTUALE_DIFFICOLTA_FACILE 35 / 100
#define PERCENTUALE_DIFFICOLTA_MEDIA 25 / 100
#define PERCENTUALE_DIFFICOLTA_DIFFICILE 15 / 100

typedef enum {
	TASTO_BACKSPACE = 8,
	TASTO_ESC = 27,
	TASTO_INVIO = 13,
	CHAR_0 = 48,
	CHAR_1 = 49,
	CHAR_2 = 50,
	CHAR_3 = 51,
	CHAR_4 = 52,
	CHAR_5 = 53,
	CHAR_6 = 54,
	CHAR_7 = 55,
	CHAR_8 = 56,
	CHAR_9 = 57,
	CHAR_A = 65,
	CHAR_G = 71,
	CHAR_a = 97,
	CHAR_z = 122
} ASCII_CODE;

typedef enum {
	FALSO,
	VERO
} bool_t;

#endif
