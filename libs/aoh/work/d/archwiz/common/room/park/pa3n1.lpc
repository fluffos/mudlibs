#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Wild Dog Area");
  SetIntLong(
"Bones lie everywhere on the ground.  An old dog is lying "
"on the forest's ground, pleading you to be kind.\n");
  SetIndoors(0);
  AddDetail(({"area","wild dog area","dog area"}),#'IntLong);
  AddDetail(({"bones","bone"}),
"The bones look broken as if a dog had eaten them.\n");
  AddExit("west","./pa4n1");
  AddExit("east","./pa2n1");
  AddExit("south","./pa3n2");
  AddItem(MONSTER("park/dog"),REFRESH_HOME);
}
