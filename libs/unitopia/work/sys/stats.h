// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/stats.h
// Description: Defines fuer query_one_stat(), ...
//
// $Log: stats.h,v $
// Revision 1.6  2014/05/20 22:44:00  gnomi
// Int-Werte brauchen nicht gerundet werden.
//
// Revision 1.5  2003/07/31 00:52:07  menaures
// Ausgabe von PRINT_STAT verbessert
//
// Revision 1.4  2003/06/22 05:29:37  menaures
// Makros fuer Float-Stats
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef STATS_H
#define STATS_H 1

#define STAT_NUMBER	4

#define STAT_STR	0
#define STAT_INT	1
#define STAT_CON	2
#define STAT_DEX	3
#define STAT_NAMES	({ "Staerke", "Intelligenz",\
			   "Ausdauer", "Geschicklichkeit" })

#define INIT_STAT_ARRAY ({ 1, 1, 1, 1 })

// Minimale Intelligenz, um sprechen zu koennen
#define MIN_INT_COMM	30
// Minimale Intelligenz, um eine Waffe fuehren zu koennen
#define MIN_INT_WIELD	25
// Minimale Intelligenz, um lesen zu koennen
#define MIN_INT_READ    30

/*
FUNKTION: ROUND_STAT
DEKLARATION: int ROUND_STAT(float)
BESCHREIBUNG:
Der zu einem Float-Stat zugehoerige Integer-Wert ergibt
sich durch ROUND_STAT mit dem Float-Wert als Argument.

Um Inkonsistenzen / Rundungsfehler zu vermeiden, sollten Integer-Werte
fuer Stats ausschliesslich mit diesem Makro berechnet werden.
VERWEISE: PRINT_STAT
GRUPPEN: spieler, monster, skill
*/
#define ROUND_STAT(x) (intp(x)?(x):to_int(round(x*10)/10.0))

/*
FUNKTION: PRINT_STAT
DEKLARATION: string PRINT_STAT(int|float)
BESCHREIBUNG:
Wenn Stat-Werte an Spieler ausgegeben werden sollen, so sollte
der entsprechende String (insbesondere bei Float-Stats) mit
PRINT_STAT erstellt werden.

Das Makro erzeugt einen String der Form "45,6".
VERWEISE: ROUND_STAT
GRUPPEN: spieler, monster, skill
*/
#define PRINT_STAT(x) (intp(x) || round(x*10) == ROUND_STAT(x)*10 ? \
                       to_string(ROUND_STAT(x)) : \
                       sprintf("%d,%d", ROUND_STAT(x), \
                       round(x*10) - ROUND_STAT(x)*10))

#define NEW_STATS

#include "monster_master.h"

#endif // STATS_H
