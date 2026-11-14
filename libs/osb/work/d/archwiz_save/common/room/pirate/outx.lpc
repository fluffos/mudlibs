#include "path.h"
#include <moving.h>

inherit "/std/room";

int go_west() {
  write("You step on the hot lava. OUCH! That hurts!!!\n");
  if (!this_player()) return 0;
  this_player()->DoDamage(85-this_player()->QueryDex()*2);
  if (!this_player()) return 0;
  this_player()->move(PIRATE("coals1"),M_GO,"west");
  return 1;
}

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong(
"You're in a cavern. Ahead streams of lava crosses the ground to "
"the west.\n");
  SetIndoors(1);
  SetBright(10);
  AddDetail(({"lava","stream","streams"}),"You feel the heat of the lava.\n");
  AddExit("east","./deep10");
  AddExit("west",#'go_west);
}
