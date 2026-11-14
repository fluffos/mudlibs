/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"

// the old file points to /d/avalon/common/std/road.c,
// which doesn't exist here.. 
// Sonic, 18-May-1997
//inherit HOUSEROAD;
inherit "/std/room";

create() {
  ::create();
  SetIntShort("South Avenue");
  SetIntLong(
"You are on South Avenue, a quiet suburban lane running east-west. "
"To the south are the ruins of the psionics' guild.\n"
    );
  AddDetail("shack","It isn't here anymore.\n");
  AddExit("south",PSI("psi_ruins1"));
  AddExit("west","./boul3");
  AddExit("east","./southave4");
  SetIndoors(0);
}
