/* 
 * /p/daemon/housed/sys/upgade.h - Deklarationen zum Upgraden
 *
 * (c) 2000 Mud Silberland - Adrian Holzwarth / Anatol@Silberland
 *
 *  2012 25 01 Revision 0.2   + HOUSE_UPGRADE_DESC
 *  2000 12 01 Revision 0.1   Initial
 *
 */

#ifndef _HOUSED_UPGRADE_H_
#define _HOUSED_UPGRADE_H_

#include "housed.h"

#define UPGRADE(x,y)          call_other(HOUSED_UPGRADE,"Upgrade",x,y)
#define MAY_UPGRADE(x,y)      call_other(HOUSED_UPGRADE,"MayUpgrade",x,y)
#define ALREADY_UPGRADED(x,y) call_other(HOUSED_UPGRADE,"AlreadyUpgraded",x,y)

// Upgrade-Array-Eintraege:

#define HOUSED_UPGRADE_FN       0  // Filename(s) der erlaubten Objekte
#define HOUSED_UPGRADE_TYPE     1  // Raum oder Goodie ?
#define HOUSED_UPGRADE_INFO     2  // Anzahl Raeume / Goodie-Filename
#define HOUSED_UPGRADE_HOUSENO  3  // Fuer welches Haus (default:0) gilt das?
#define HOUSED_UPGRADE_DESC     4  // Kurze (Einwort-)Beschreibung fuer Spieler
#define HDUPT_ROOM         0
#define HDUPT_GOODIE       1

// Fehlermeldungen:

#define HOUSE_UPGRADE_BAD_CALL           -1 // Die Parameter waren unpaesslich
#define HOUSE_UPGRADE_ACCESS_FAILURE     -2 // Objekt durfte nicht upgraden
#define HOUSE_UPGRADE_NO_SUCH_HOUSE      -3 // Das Seherhaus gibt es nicht.
#define HOUSE_UPGRADE_HOUSE_LOAD_FAIL    -4 // Haus konnte nicht geladen werden.
#define HOUSE_UPGRADE_ALREADY_DONE       -5 // Der Upgrade ist schon erledigt.
#define HOUSE_UPGRADE_FAILED             -6 // IRGENDWAS ging schief :(

#endif
