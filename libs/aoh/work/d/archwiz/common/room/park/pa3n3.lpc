#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Stinking Skunk Area");
  SetIntLong(
"Smell of skunk's spray is everywhere in the air.  Your "
"nose winkles up from the smell.  Your eyes are watering.\n");
  SetIndoors(0);
  SetIntSmell("It smells horrible in here.\n");
  AddDetail("area",#'IntLong);
  AddExit("west","./pa4n3");
  AddExit("east","./pa2n3");
  AddExit("south","./pa3n4");
  AddExit("north","./pa3n2");
  AddItem(MONSTER("park/skunk"),REFRESH_HOME,3);
}
