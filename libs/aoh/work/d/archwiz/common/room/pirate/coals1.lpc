#include <combat.h>
#include <moving.h>
#include "path.h"

inherit "/std/room";

int west() {
  if (!this_player()) return 0;
  write("You make another big step. You're again hurt badly!\n");
  this_player()->Defend(72-(this_player()->QueryDex()*3),DT_FIRE);
  this_player()->move(PIRATE("coals2"),M_GO,"west");
  return 1;
}

create() {
  ::create();
  SetBright(20);
  SetIntShort("hot lava");
  SetIntLong(
"You are standing on hot lava. To the west can be seen more of it.\n");
  AddDetail(({"lava","hot lava"}),
"You jump up and down while resting on the hot lava.\n");
  AddExit("west",#'west);
  HideExit("west",1);
  AddExit("east","./outx");
}
