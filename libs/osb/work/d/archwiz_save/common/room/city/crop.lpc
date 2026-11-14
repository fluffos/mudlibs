inherit "std/room";
#include "path.h"

create() {
  ::create();
  SetIntShort("Fields");
  SetIntLong(
"You are in the middle of the fields where the city grows all its crops. "
"The road runs north and south.\n");
  AddDetail(({"field","fields"}),
  "The fields expand to all directions.\n");
  AddExit("north", "./vill_shore");
  AddExit("south", "./woodbridge");
  SetIndoors(0);
}

