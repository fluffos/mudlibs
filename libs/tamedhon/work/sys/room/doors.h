// SilberLand MUDlib
//
// sys/room/doors.h -- door definitions, managed by doormaster
//
// $Date: 2006/06/01 11:00:00 $
/* $Revision: 1.4 $
 * $Log: doors.h,v $
 * Revision 1.4  2006/06/01 11:00:00  Serii
 * D_OPENMSG, D_CLOSEMSG, D_RESET_OPENMSG, D_RESET_CLOSEMSG, D_LOCKMSG und D_UNLOCKMSG eingebaut
 *
 * Revision 1.3  1997/03/31 15:38:55  Woody
 * prepared for revision control
 *
 * Revision 1.2  1996/11/21  Woody
 * D_CLOSETESTFUNC
 *
 * Revision 1.1  1996/03/11  02:16:00  Mupfel
 * Komplett uebernommen aus /sys/doorroom.h
 *
 */

#ifndef __ROOM_DOORS_H__
#define __ROOM_DOORS_H__

// properties

#define DOOR_MASTER  "/p/daemon/doormaster"
#define P_DOOR_INFOS "door_infos"   // Informationen

#define DOOR_OPEN     0x01 // Tuer initial offen
#define DOOR_CLOSED   0x02 // Tuer initial zu
#define DOOR_NEEDKEY  0x08 // Man braucht einen Schluessel zum Oeffnen
#define DOOR_CLOSEKEY 0x10 // Man braucht einen Schluessel zum Schliessen
#define DOOR_RESET_CL 0x20 // Tuer schliesst sich bei jedem reset()
#define DOOR_RESET_OP 0x40 // Tuer oeffnet sich bei jedem reset()

#define D_DEST 0
#define D_CMDS 1
#define D_IDS 2

// properties
// Ab hier die aenderbaren Eigenschaften der Tuer
#define D_FLAGS 3
#define D_LONG 4
#define D_SHORT 5
#define D_NAME 6
#define D_GENDER 7
#define D_FUNC 8
// Funktion, die VOR dem Durchschreiten der Tuer aufgerufen wird (im Startraum)
#define D_MSGS 9
// Messages fuer Move
#define D_FUNC2 10
// Funktion, die NACH dem Durchschreiten der Tuer aufgerufen wird (im Zielraum)
#define D_TESTFUNC 11
// Funktion, die testet, ob die Tuer durchschritten werden darf (im Startraum)
#define D_KEYTESTFUNC 12
// Funktion, die testet, ob die Tuer aufgeschloessen werden darf; wird
// im Startraum aufgerufen, nachdem der richtige Schluessel vorhanden ist
#define D_OPENTESTFUNC 13
// Funktion, die testet, ob die Tuer geoeffnet werden darf (im Startraum)
// Wird, wenn Schluessel noetig, nach D_KEYTESTFUNC aufgerufen.
// Wenn diese Funktion 1 (oder einen Wert ungleich 0) zurueckgibt,
// so wird die Tuer nicht geoeffnet (aber dennoch mit return 1
// zurueckgekehrt, man muss also keine notify_fail() setzen, sollte
// den Spieler aber doch per write() informieren, dass das Oeffnen
// der Tuer fehlgeschlagen ist).
#define D_CLOSETESTFUNC 14
// Funktion, die testet, ob die Tuer geschlossen werden darf (im Startraum)
// Fuer die Implementierung gilt dasselbe wie fuer D_OPENTESTFUNC.

#define D_OPENMSG 15
// wird ausgegeben wenn die tuer geoeffnet wird
#define D_CLOSEMSG 16
// wird ausgegeben wenn die tuer geschlossen wird
#define D_RESET_OPENMSG 17
// wird ausgegeben wenn sich die tuer beim reset oeffnet ( 3 element array )
#define D_RESET_CLOSEMSG 18
// wird ausgegeben wenn sich die tuer beim reset schliesst ( 3 element array )
#define D_LOCKMSG 19
// wird ausgegeben wenn man die tuer abschliesst ( 3 element array )
#define D_UNLOCKMSG 20
// wird ausgegeben wenn man die tuer aufschliesst ( 3 element array )

#define D_MINPROPS 3
#define D_MAXPROPS 20

#define D_STATUS_LOCKED -2
#define D_STATUS_CLOSED -1
#define D_STATUS_OPEN    1

#endif // __ROOM_DOORS_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_DOORS_H_PROTO__
#define __ROOM_DOORS_H_PROTO__

// prototypes
mapping QueryAllDoors();
int QueryDoorStatus(string dest);
void SetDoorStatus(string dest, int x);
varargs int NewDoor(mixed cmds, string dest, mixed ids, mixed props);
void    init_doors ();
string  look_doors ();
void    reset_doors ();
varargs int go_door (string str);
int     oeffnen (string str);
int     schliessen (string str);
int     set_doors (string *cmds, int open);
varargs string GetExits(object viewer); 

#endif // __ROOM_DOORS_H_PROTO__

#endif // NEED_PROTOTYPES
