/* NetDead 
**
** Ein Raum fuer Netztote Spieler. 
**
**   07-Feb-92 [m] 
**   14-Jun-92 [m] Adapted for native mode.
**
**  [m] Mateese
*/

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort ("The Hall of Netdead Players");
  SetIntLong (
"This is the famous room for netdead players.\n"+
"It is large and dimly lit to give a comfortable environment\n"+
"for the players sleeping here.\n"+
"Awake players may leave to the church or expand their\n"+
"knowledge (a bit) by typing 'info'.\n"
              );
  AddExit ("west", "room/church");
  AddRoomCmd ("info", "finfo");
  /* SetIntLight(1); */
  Set(P_INDOORS, 1);
}

query_netdead_room() { return 1; }

finfo (str) {
  if (str) return 0;
  if (PL_LEVEL > 20) return PL->more (MP+"data/netdead.winfo");
  return PL->more (MP+"data/netdead.info");
}
 
query_no_steal() { return 1; }
