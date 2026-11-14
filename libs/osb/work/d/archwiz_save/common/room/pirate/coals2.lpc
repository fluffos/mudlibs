#include <combat.h>
#include "path.h"
#include <moving.h>

inherit "/std/room";

int east() {
  if (!this_player()) return 0;
  write("You are hurt badly while you move on the hot lava.\n");
  this_player()->Defend(71-(this_player()->QueryDex()*3),DT_FIRE);
  this_player()->move(PIRATE("coals1"),M_GO,"east");
  return 1;
}

create() {
  ::create();
  SetBright(20);
  SetIntShort("on hot lava");
  SetIntLong(
"You are standing on hot lava. To the west is some piece of ground without "
"lava and a door.\n");
  AddExit("east",#'east);
  HideExit("east",1);
  AddExit("west","./safe");
}
