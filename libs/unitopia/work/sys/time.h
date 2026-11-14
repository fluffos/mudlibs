// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/time.h
// Description: wichtige Defines fuer die Uhrzeit
//
// $Log: time.h,v $
// Revision 1.12  2003/06/20 02:51:24  gnomi
// TIME_ADJUST korrigiert.
//
// Revision 1.11  2003/01/25 04:21:31  gnomi
// Kommentar ueber den Wert von BEGIN_DARKNESS/BEGIN_DAYLIGHT
//
// Revision 1.10  2002/10/29 01:45:32  gnomi
// TIME_ADJUST geaendert. Muss nun nicht staendig an Winter/Sommerzeit
// angepaasst werden.
//
// Revision 1.9  2002/03/31 18:52:40  freaky
// auf Sommerzeit umgestellt
//
// Revision 1.8  2002/01/10 12:25:36  freaky
// Doku von Pulami uebernommen.
//
// Revision 1.7  2001/11/15 22:10:59  gnomi
// Auf Winterzeit umgestellt.
//
// Revision 1.6  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.5  2001/04/06 15:39:12  freaky
// auf Sommerzeit umgestellt.
//
// Revision 1.4  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_TIME_H_
#define LPC_TIME_H_ 1

/* Indices into the array returned from gmtime() and localtime(). */

#define TM_SEC    0  /* Seconds (0..59) */
#define TM_MIN    1  /* Minutes (0..59) */
#define TM_HOUR   2  /* Hours (0..23) */
#define TM_MDAY   3  /* Day of the month (1..31) */
#define TM_MON    4  /* Month of the year (0..11) */
#define TM_YEAR   5  /* Year (e.g.  2001) */
#define TM_WDAY   6  /* Day of the week (Sunday = 0) */
#define TM_YDAY   7  /* Day of the year (0..365) */
#define TM_ISDST  8  /* TRUE: Daylight saving time */

#define TM_MAX 9  /* Number of entries in the array */


#define DAY		86400
#define WEEK		604800
#define MORNING		14400           /* 4 Uhr */
// Real - Sekunden eines Spielzeittages
#define VDAY		9600

// #define TIME_ADJUST 3600	// +3600 wegen 1h bei Winterzeit
// #define TIME_ADJUST 7200	// +7200 wegen 2h bei Sommerzeit
#define TIME_ADJUST (3600*((localtime(time())[TM_HOUR]-gmtime(time())[TM_HOUR]+24)%24))

#define SUNDAY_ADJUST   (TIME_ADJUST-259200)

#define BIRTHDAY        705948522    /* 15.5.1992 18:48:42 */

#define TIMEWARP        9

// Entsprechen dem Rueckgabewert von vclock():
#define BEGIN_DARKNESS 210000
#define BEGIN_DAYLIGHT  41000

/*
FUNKTION: IS_NIGHT
DEKLARATION: int IS_NIGHT
BESCHREIBUNG:
Liefert 1 bei Nacht und 0 bei Tag.
Man beachte, dass hinter IS_NIGHT keine Klammern stehen.
VERWEISE: IS_DAY, IS_NIGHT
GRUPPEN: zeit
*/

#define IS_NIGHT (vclock()>=BEGIN_DARKNESS || vclock()<BEGIN_DAYLIGHT)

/*
FUNKTION: IS_DAY
DEKLARATION: int IS_DAY
BESCHREIBUNG:
Liefert 1 bei Tag und 0 bei Nacht.
Man beachte, dass hinter IS_DAY keine Klammern stehen.
VERWEISE: IS_DAY, IS_NIGHT
GRUPPEN: zeit
*/

#define IS_DAY   (vclock()>=BEGIN_DAYLIGHT && vclock()<BEGIN_DARKNESS)

// Spielzeitdauer von 28 Jahren:
// Die 28 ist eine total magische Zahl:
// 28 ist die kleinste (Jahrs-)Zahl, nach denen die Wochentage
// uebereinstimmen, und die durch 4 teilbar ist, damit die
// Schalttage korrekt sind. Und das Ganze jetzt noch in
// Spielsekunden, also durch TIMEWARP teilen...
#define SEC_IN_28_YEARS 98179200

// Real - Sekunden eines Spielzeittages
// 24*60*60 / TIMEWARP
#define REAL_SECONDS_PER_DAY 9600

#endif /* LPC_TIME_H_ */
