/* Paracelsus: Headerfile fuer den RAGE-Raum */
/* Woody: Dankend erhaltend von Paracelsus, fuers SL ueberarbeitet */

#ifndef _PARA_RAGE_H_
#define _PARA_RAGE_H_

// ---------- Pfade ----------

#define RAGE_BASEPATH(x) ("/d/ebene/Midas/room/spiele/rage/"+x)

#define RG_SAVEFILE  RAGE_BASEPATH("save")

#define RAGE_NAME    "Rage"

#define RG_HELP_AKT  RAGE_BASEPATH("akt.txt")
#define RG_HELP_KOM  RAGE_BASEPATH("kom.txt")
#define RG_HELP_REG  RAGE_BASEPATH("reg.txt")
#define RG_HELP_TRM  RAGE_BASEPATH("trm.txt")

// ---------- Der Ausgang ----------

#define RG_EXIT_PATH "/d/ebene/Midas/room/spiele/maexchen_raum"

// ---------- Pre-Text der Ausgabe ----------

#define RG_CHANNEL   "[<Rage>] "

// ---------- Klassen von Spielkarten ----------

#define RGC_RED      1
#define RGC_YELLOW   2
#define RGC_GREEN    3
#define RGC_BLUE     4
#define RGC_BLACK    5
#define RGC_OCHRE    6
#define RGC_ACTION   7

// ---------- Konfiguration der Kartenzahl ----------

#define RGN_PLUS     2
#define RGN_MINUS    2
#define RGN_JOKER    2
#define RGN_CHANGE   3
#define RGN_BLOCK    3
#define RGN_FROM     0
#define RGN_TO       15

// ---------- Kartenzahl es in der ersten Runde ----------

#define RAGE_START   10

// ---------- Spielerzahlen ----------

#define RAGE_MIN_PLAYER 4
#define RAGE_MAX_PLAYER 10

// ---------- String fuer die Anzahl der Stuehle ----------

#define RG_CHAIRS "acht"

// ---------- Timeout fuer Netztote in Minuten ----------

#define RAGE_TIMEOUT 5

// ---------- Indices fuer das Game-Mapping ----------

#define RA_DECK      0
#define RA_SCORE     1
#define RA_SAY       2
#define RA_TAKEN     3
#define RA_TOTAL     4

// ---------- Indices fuer Interna-Mapping ----------

#define RI_TCLASS    0
#define RI_TRUMP     1
#define RI_STEP      2
#define RI_CHANGE    3
#define RI_SAY       4
#define RI_COLOR     5
#define RI_NEXT      6
#define RI_ACLASS    7
#define RI_JOKER     8

// ---------- Debugging ----------

//#define RDB(x)
#define RDB(x)       tell_room(TO,break_string(x,78,"[<RDB>] "))

#endif // _PARA_RAGE_H_
