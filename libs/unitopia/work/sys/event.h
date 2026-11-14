// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/event.h
// Description:	Defines fuer die Events des Kuriers
// Author:	Garthan
//
// $Log: event.h,v $
// Revision 1.11  2011-02-04 23:20:54  gnomi
// Neue experimentelle WebMUD-Funktionalitaeten.
//
// Revision 1.10  2003/11/04 03:21:46  gnomi
// Konstanten fuers Ignorieren.
//
// Revision 1.9  2002/12/05 00:47:31  gnomi
// Defines fuer die Datei aus welcher die prevents eingelesen werden.
//
// Revision 1.8  2002/11/20 04:13:10  gnomi
// COMM_V entfernt.
//
// Revision 1.7  2001/12/12 07:25:33  gnomi
// Gildenfilter rausgenommen.
//
// Revision 1.6  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef EVENT_H
#define EVENT_H 1

#include "config.h"

#define EVENT_FILE "/nosave/adm/EVENTS"
#define PREVENT_FILE "/nosave/adm/KEIN_KURIER"

#define BEISPIEL   (HELP_PATH+"/kurier.rest/BEISPIEL")
#define FLAGS      (HELP_PATH+"/kurier.rest/FLAGS")

/*
#define EV_ID_NR 0
#define EV_ID_STRING 1
#define EV_LEVEL 2
#define EV_SHOW_INVIS 3
#define EV_FUNC 4
#define EV_GILDE 5
#define EV_DESC 6
#define EV_DISTRIB 7
*/

#define EVR_ID_STRING	  0
#define EVR_LEVEL	  1
#define EVR_DISTRIB	  2
#define EVR_ID_NR	  3

// Die Flags fuer den Parameter beim Aufruf von event im Player
// Gratsfilter wuerde bei der Meldung zuschlagen
#define EVF_GRATSFILTER   1
// Die Meldung ist eine Reaktion auf einen bruelle-Befehl
// Es wird mindestens "Ok." ausgegeben.
#define EVF_FEEDBACK      2

// Flags fuer den Kurierpuffer und Meldungspuffer des SpielerS
#define PUFFER_GRATSFILTER     EVF_GRATSFILTER
// Spieler war nicht interaktiv
#define PUFFER_NON_INTERACTIVE 2
// Text nicht einruecken (fuer Statue-Meldung oder Befehlspuffer)
#define PUFFER_NOT_INDENT      4

//Die Eintraege im Array events im Player
#define EVC_ID_NR	  0
#define EVC_STATUS	  1
#define EVC_PERSONS	  2
#define EVC_COLOUR	  3

//Fuer commands und commands_gilden im Player
#define EVC_COMM	  0
#define EVC_COMM_AN	  1
#define EVC_COMM_ACCESS   2
#define EVC_GILDEN_NAME   2

// Bits im EVC_STATUS-Bitstring
#define COMM_S		  1
#define COMM_N		  2
#define COMM_D		  3
// Bit fuer Gouverneure - gibt es nicht mehr
// #define COMM_V		  4
#define COMM_A		  5
#define COMM_PERSONS	  6
#define COMM_LEVELS	  7
#define COMM_M		  8
#define COMM_MICH	  9
#define COMM_GRATSFILTER 10
#define COMM_GAESTE	 11
#define COMM_WEBMUD	 12 // 2 Bits breit
#define COMM_WEBMUD_WIDTH 2

// COMM_WEBMUD-Werte
#define CW_MAIN_WINDOW	  0
#define CW_OWN_WINDOW	  1
#define CW_BOTH_WINDOWS	  2

// verschiedene Modi, die sich auf ALLE Events, die ein
// Spieler erhaelt, auswirken
#define EVF_G_MODE_BRACKETS      1

// Ignoriere-Moeglichkeiten
#define IGN_SAY		1	// Sage
#define IGN_TELL	2	// Rede
#define IGN_SHOUT	4	// Bruelle
#define IGN_SOUL	8	// Seele. Ich
#define IGN_WEAPONS	16	// Fuehren, Senken
#define IGN_ACTIONS	32	// Schauen, Mustern, Riechen, Fuehlen, Horchen
				// Anziehen, Ausziehen, Essen, Drinken, Lesen

#define MAX_IGNORED	9

#endif // EVENT_H
