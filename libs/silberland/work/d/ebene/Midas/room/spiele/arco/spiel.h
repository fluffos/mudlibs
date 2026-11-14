// 01.02.00 Archon: - erstellt 
/*
 Rev 1.4 18.01.2003 Archon: sl-anpassungen
*/

#ifndef ARCO_FILES_H
#define ARCO_FILES_H

#include "def.h"

#define INFO_COL1 "spiel-text"
#define INFO_COL2 "spiel-info"
#define INFO_COL3 "spiel-warn"
#define INFO_COL4 "spiel-info"
#define INFO_COL5 "spiel-sieg"

#define ARCO_ANZEIGE  SPIEL "arco_anzeige"
#define ARCO_KARTEN   SPIEL "arco_karten"
#define ARCO_TOP      SPIEL "arco_topliste" 
#define ARCO_TOPFREI  SPIEL "arco_topliste_frei"

#define ARCO_PLAYER 0
#define ARCO_TURM 1
#define ARCO_MAUER 2
#define ARCO_STEINBRUCH 3
#define ARCO_MAGIE 4
#define ARCO_ZOO 5
#define ARCO_STEINE 6
#define ARCO_JUWELEN 7
#define ARCO_MONSTER 8
#define ARCO_KARTE1 9
#define ARCO_KARTE2 10
#define ARCO_KARTE3 11
#define ARCO_KARTE4 12
#define ARCO_KARTE5 13
#define ARCO_KARTE6 14
#define ARCO_NAME 15

#define FARBE_ROT 1
#define FARBE_BLAU 2
#define FARBE_GRUEN 3

#define KARTE_NAME 0
#define KARTE_FARBE 1
#define KARTE_KOSTEN 2 //kosten
#define KARTE_BEDINGUNG 3 //wenn bedinung gesetz dann wahr=aktion1 sonst aktion 2 - aktion3,4 gehen nicht 
#define KARTE_AKTION1 4 //wieviel
#define KARTE_AKTIONART1 5 //von was
#define KARTE_AKTION2 6
#define KARTE_AKTIONART2 7
#define KARTE_AKTION3 8
#define KARTE_AKTIONART3 9
#define KARTE_AKTION4 10
#define KARTE_AKTIONART4 11

#define AKTION_SCHADEN 1
#define AKTION_SCHADEN_SELBST 2
#define AKTION_SCHADEN_ALLE 3
#define AKTION_SCHADEN_TURM 4
#define AKTION_SCHADEN_TURM_SELBST 5
#define AKTION_SCHADEN_TURM_ALLE 6
#define AKTION_MAGIE 7
#define AKTION_MAGIE_SELBST 8
#define AKTION_MAGIE_ALLE 9
#define AKTION_STEINBRUCH 10
#define AKTION_STEINBRUCH_SELBST 11
#define AKTION_STEINBRUCH_ALLE 12
#define AKTION_ZOO 13
#define AKTION_ZOO_SELBST 14
#define AKTION_ZOO_ALLE 15
#define AKTION_STEINE 16
#define AKTION_STEINE_SELBST 17
#define AKTION_STEINE_ALLE 18
#define AKTION_JUWELEN 19
#define AKTION_JUWELEN_SELBST 20
#define AKTION_JUWELEN_ALLE 21
#define AKTION_MONSTER 22
#define AKTION_MONSTER_SELBST 23
#define AKTION_MONSTER_ALLE 24
#define AKTION_TURM 25
#define AKTION_TURM_SELBST 26
#define AKTION_TURM_ALLE 27
#define AKTION_MAUER 28
#define AKTION_MAUER_SELBST 29
#define AKTION_MAUER_ALLE 30
#define AKTION_NEUER_ZUG 31
#define AKTION_ABLEGEN 32
#define AKTION_ZIEHEN 33
#define AKTION_RESOURCEN 34 //alle resourcen um x aendern
#define AKTION_RESOURCEN_SELBST 35
#define AKTION_RESOURCEN_ALLE 36
#define AKTION_GLEICHGEWICHT 37 //magie aller = magie hoechster
#define AKTION_SCHADEN_MAUER 38
#define AKTION_SCHADEN_MAUER_SELBST 39
#define AKTION_SCHADEN_MAUER_ALLE 40
#define AKTION_STEINBRUCH_STEINBRUCH_GEGNER 41 //Steinbruch = Steinbruch des Gegners
#define AKTION_MAUERTAUSCH 42
#define AKTION_KLEINSTE_MAUER 43 //spieler mit kleinster mauer -1 zoo 2 turmschaden

#define BEDINGUNG_MAUER1 1 //Wenn Mauer == 0
#define BEDINGUNG_MAGIE1 2 //Wenn Magie > Magie des Gegners
#define BEDINGUNG_MAUER2 3 //Wenn Mauer Gegner > 0
#define BEDINGUNG_STEINBRUCH1 4 //Wenn Steinbruch<Steinbruch des Gegners
#define BEDINGUNG_MAUER3 5 //Wenn Mauer Gegner == 0
#define BEDINGUNG_MAUER4 6 //Wenn Mauer > Mauer Gegner
#define BEDINGUNG_ABLEGEN1 7 //Karte darf nicht abgeworfen werden
#define BEDINGUNG_TURM1 8 // Wenn Turm < Turm Gegner
#define BEDINGUNG_TURM2 9 // Wenn Turm > Mauer Gegner
#define BEDINGUNG_ZOO1 10 // Wenn Zoo < Zoo Gegner

#endif