#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Land of Rabid Squirrel");
  SetIntLong(
"Everywhere you look, you see a lot of corpses of dead "
"animals.  This must be the resting place of the sick "
"and tired animal.\n");
  SetIndoors(0);
  AddDetail(({"corpses","corpse","dead animals","dead animal"}),
"They look rotten.\n");
  AddExit("west","./pa3n3");
  AddExit("east","./pa1n3");
  AddExit("south","./pa2n4");
  AddExit("north","./pa2n2");
  AddItem(MONSTER("park/squirrel"),REFRESH_HOME,2);
}
