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
"To the south you can see the South Plaza.\n");
  AddExit("west",  "./southave3");
  AddExit("east",  "./farmland");
  AddExit("south", RANDY("plaza"));
  SetIndoors(0);
}
