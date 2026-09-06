#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("A dimly lit path");
  SetIntLong(
"You are walking on a dimly lit path leading east and west. To the south the "
"forest is much thicker than to the north. There seems to be kind of a path "
"to the south, but you are not sure, too many trees all around you. "
"A big stream flows through the forest from the north to the south.\
The path to the south is blocked by a mess of bushes.\n");
  AddExit("west", "./forest2");
  AddExit("east", "./forest4");
/*
 * I removed the hell-exit to the south due to some errors.
 * Sonic, 06-June-1997
  AddExit("south", "/d/hell/common/room/dark_tower/path1");
*/
  SetIndoors(0);
}
