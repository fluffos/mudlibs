/*
 * Tamedhon MUDlib
 * ---
 * /secure/exploration.h
 * Definitionen fuer den Exploration Master, maintained by Woody
 * ---
 * $Date: 1997/08/29 21:57:45 $
 * $Revision: 1.8 $
 * $Log: exploration.h,v $
 *
 * Revision 1.10 2007-02-08 Gralkor
 * EP_FOR_AP zurueck auf 10 (viel weniger FP)
 *
 * Revision 1.9	2006-02-05  Gralkor
 * Updatezeiten der Schwankung verringert (von 300 auf 100)
 *
 * Revision 1.8  1997/08/29 21:57:45  Feyaria
 * EP_FOR_AP auf 13
 *
 * Revision 1.7  1997/06/25 10:59:19  Woody
 * EP_PUB, EP_PER_AP auf 12 erhoeht
 *
 * Revision 1.6  1997/04/21 13:23:48  Woody
 * EP_PER_AP auf 9 erhoeht
 *
 * Revision 1.5  1997/03/15 22:59:31  Woody
 * prepared for revision control
 *
 * Revision 1.4  96-10-15  Woody
 * EPLOGFILE
 *
 * Revision 1.3  96-10-10  Woody
 * EP_SENSE
 *
 * Revision 1.2  96-10-06  Woody
 * EPAVGFILE
 *
 * Revision 1.1  96-10-01  Woody
 * P_EP_NUM_FOR_AP, EP_FOR_AP
 *
 * Revision 1.0  96-09-25  Woody
 * Erste Implementation
 *
 */

#ifndef  __EXPLORATION_H__
#define  __EXPLORATION_H__

/*
** Properties
*/

#define P_LP		"lp"
#define P_EP		"ep"
#define P_EP_NUM	"ep_num"
#define P_EP_NUM_FOR_AP	"ep_num_for_ap"

/*
** Dateinamen
*/

#define EPMASTER	"/secure/explorationmaster"
#define EPSAVEFILE	"/secure/ARCH/exploration"
#define EPDUMPFILE	"/secure/ARCH/epobjects"
#define EPAVGFILE	"/secure/ARCH/epaverage"
#define EPLOGFILE	"ARCH/ep.log"

/*
** Symbolic Indices
*/

/* EP-Typen */
#define EP_DETAIL	0	// Read/Special/Detail
#define EP_EXIT		1	// (Special) Exit
#define EP_CMD		2	// AddCmd()-Funktion
#define EP_INFO		3	// Infos von NPCs
#define EP_SENSE	4	// Geruch/Geraeusch im Raum
#define EP_MISC		5	// diverse, zB. GiveExplorationPoint()
#define EP_PUB		6	// Speise/Getraenk in einer Kneipe
#define EP_TYP_MAX	6	// Letzter vorhandener Typ

#define EP_TYP_STR	({ "det", "exit", "cmd", "info", \
                           "sens", "misc", "pub" })

/* Mapping-Indices */
#define EPM_KEY		0	// Die Keys (Detail, Exit, whatsoever)
#define EPM_NUM		1	// Nr. des EP (Offset fuer P_EP_NUM Bitstring)
#define EPM_EPS		2	// Anzahl der EPs fuer die Aktion

/* moegliche vom Master zurueckgegebene Fehler */
#define EPERR_NOT_ARCH	   -1	// Aktion ist Erzmagiern vorbehalten
#define EPERR_NOT_MASTER   -2	// Aktion ist dem EP-Master vorbehalten
#define EPERR_INVALID_OB   -3	// Objekt nicht fuer EP zugelassen
#define EPERR_NO_ENTRY	   -4	// Eintrag nicht gefunden
#define EPERR_INVALID_ARG  -5	// Ungueltiges Argument

/* diverse Konstanten */

#define EPS_MAX		10	// maximal vergebbare EP fuer eine Aktion
#define MIN_EP		30	// minimale EP; (30)  fuer Statistik
#define TIME_UPD_EPNUM	180	// Zeit die mind. verstreichen muss, bis
				// Aenderungen der EP_NUM sichtbar werden
#define TIME_UPD_AVG	100	// Update-Intervalle fuer Durchschnitts-
				// EP-Berechnung
#define EP_PER_AP	10	// 11 Forscherpunkte geben einen Attributpunkt

#define LF_LOG      "/log/ARCH/EP_TOO_FAST"
#define LF_LOG_NAME "/log/ARCH/exploration/"
#define LF_TIME     30    // wenn < 30 Sekunden zw. 2 FPs
#define LF_WARN      5    // ab dem 5. derart gefundenen FP E+ warnen, loggen
#define vPlayerNum  15    // 15 virtuelle Spieler
#define vAverage    40    // FP Anzahl der virtuellen Spieler

#endif

