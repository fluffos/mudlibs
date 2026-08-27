/*
 *  Definicje wspierajace uzywanie kalendarza i ruchow cial niebieskich.
 *
 *  /sys/mudtime.h
 *
 *  dzielo Silvathraeca 1997
 */

#ifndef MUDTIME_DEF
#define MUDTIME_DEF

#define MUDTIME_FILE "/sys/global/mudtime"

/* Pory dnia */

#define MT_SWIT			11	/* Przed wschodem slonca */
#define MT_WCZESNY_RANEK	12	/* Po wschodzie slonca */
#define MT_RANEK		13	/* Przed poludniem */
#define MT_POLUDNIE		14	/* W poludnie */
#define MT_POPOLUDNIE		15	/* Po poludniu */
#define MT_WIECZOR		16	/* Przed zachodem slonca */
#define MT_POZNY_WIECZOR	17	/* Po zachodzie slonca */
#define MT_NOC			18	/* W nocy */

/* Pory roku */

#define MT_WIOSNA		21
#define MT_LATO			22
#define MT_JESIEN		23
#define MT_ZIMA			24

/* Kierunki geograficzne (polozenie cial niebieskich) */

#define MT_N			51
#define MT_NE			52
#define MT_E			53
#define MT_SE			54
#define MT_S			55
#define MT_SW			56
#define MT_W			57
#define MT_NW			58

#define MT_ZENIT		61
#define MT_NADIR		62

#define MT_POD_HORYZONTEM	71

/* Fazy ksiezyca */

#define MT_PELNIA		81	/* W okolicy pelni */
#define MT_PO_PELNI		82
#define MT_PIERWSZA_KWADRA	83	/* Malejacy */
#define MT_PRZED_NOWIEM		84
#define MT_NOW			85	/* Niewidoczny */
#define MT_PO_NOWIU		86
#define MT_OSTATNIA_KWADRA	87	/* Rosnacy */
#define MT_PRZED_PELNIA		88

/* Szerokosci geograficzne */

#define MT_BIEGUN_N		91	/* Polnocna strefa biegunowa */
#define MT_POLKULA_N		92	/* Polnocna strefa umiarkowana */
#define MT_ROWNIK		93	/* Strefa rownikowa */
#define MT_POLKULA_S		94	/* Poludniowa strefa umiarkowana */
#define MT_BIEGUN_S		95	/* Poludniowa strefa biegunowa */

/* Funkcje */

#define MT_PORA_DNIA_STR(x)	(MUDTIME_FILE->pora_dnia_str(x))
#define MT_PORA_ROKU_STR(x)	(MUDTIME_FILE->pora_roku_str(x))
#define MT_KIERUNEK_STR(x)	(MUDTIME_FILE->kierunek_str(x))
#define MT_FAZA_X_STR(x)	(MUDTIME_FILE->faza_ksiezyca_str(x))

#define MT_PORA_DNIA_STRB(x)	(MUDTIME_FILE->pora_dnia_strb(x))
#define MT_FAZA_X_STRB(x)	(MUDTIME_FILE->faza_ksiezyca_strb(x))

#define MT_POLOZENIE(x, y)	(MUDTIME_FILE->polozenie_ciala(x, y))
#define MT_POLOZENIE_LONG(x, y)	(MUDTIME_FILE->polozenie_ciala_long(x, y))
#define MT_FAZA_X_LONG(x, y, z) (MUDTIME_FILE->faza_ksiezyca_long(x, y, z))

/* Koniec definicji... */
#endif MUDTIME_DEF