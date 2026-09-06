#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a path around a dark tower");
  SetIntLong(
"You're on a small path which leads around a shimmering tower. To "
"the west the tower climbs high into the sky.\n");
  SetIndoors(0);
  AddDetail(({"path","small path"}),QueryIntLong());
  AddDetail(({"tower","shimmering tower","archwiz tower","administration tower"}),
"This is the administration tower of Nightfall.\n");
  AddExit("southwest","./arounde1");
  AddExit("north","./arounde3");
}
