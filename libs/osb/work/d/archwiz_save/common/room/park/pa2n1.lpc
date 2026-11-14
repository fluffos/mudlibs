#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Goblin Forest");
  SetIntLong(
"This is the forest of the Goblins!  Run while you have the "
"chance!\n");
  SetIndoors(0);
  AddDetail(({"forest","trees","tree","goblin forest"}),
"This is the forest of the goblins.. you should run!\n");
  AddExit("west","./pa3n1");
  AddExit("east","./pa1n1");
  AddExit("south","./pa2n2");
  AddItem(MONSTER("park/goblin"),REFRESH_HOME,3);
}
