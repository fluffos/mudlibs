#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("In The City Forest");
  SetIntLong(
"You are in the forest. Everywhere you look, there are trees "
"and animals. You are on a path in the forest. The path splits "
"four ways.\n");
  SetIndoors(0);
  AddDetail(({"forest","city forest","trees","tree"}),
"This is a part of the famous city forest. You see trees all\n"
"around you.\n");
  AddDetail(({"animals","animal"}),
"There are many animals living in this forest.\n");
  AddDetail("path","It splits into four ways.\n");
  AddExit("west","./pa2n4");
  AddExit("east","./paentr");
  AddExit("south","./pa1n5");
  AddExit("north","./pa1n3");
}
