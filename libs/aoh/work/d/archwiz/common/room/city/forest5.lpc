#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("A dirty street");
  SetIntLong(
"You are walking on a dirty street which turns into a path to the south. "
"To the north lies Nightfall City, the capital of this world. You can see "
"a few building and surprisingly notice, they're nothing but ruins! Does "
"the capital really look like this?\n"
"To the south you can enter the forest that surrounds the city.\n"
         );
  AddExit("north", "./row3");
  AddExit("south", "./forest4");
  SetIndoors(0);
}
