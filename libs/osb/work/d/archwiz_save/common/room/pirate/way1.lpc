#include "path.h"
#include <moving.h>

inherit "/std/room";

int do_cell() {
  if (!this_player()) return 0;
  if (!query_once_interactive(this_player())) return 0;
  return this_player()->move(PIRATE("cell"),M_GO);
}

create() {
  ::create();
  SetIntShort("A small tunnel");
  SetIntLong("You're in a small dark and dirty tunnel.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"tunnel","small tunnel","dark tunnel","dirty tunnel",
  "small dark tunnel","small dirty tunnel","small dark and dirty tunnel"}),
#'IntLong);
  AddDetail(({"walls","wall","ceiling","ground","floor"}),
"Everything is dirty around here.\n");
  AddDetail(({"dirt","mud"}),"It is muddy.\n");
  AddExit("north","./way2");
  AddExit("cell",#'do_cell);
  HideExit("cell",1);
}
