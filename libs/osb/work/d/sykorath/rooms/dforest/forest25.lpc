// made by MagicTCS 17 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write("You try to climb the tree, but the trunk is too smooth.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

create() {
  ::create();
  SetIntShort("A clearing");
  SetIntLong(
    "You are standing on a small clearing. It is surrounded by huge trees.\n"
    "The only passable way leads to the north.\n");
  AddDetail(({"clearing","small clearing"}),#'QueryIntLong);
  AddDetail(({"tree","huge tree"}),
    "Well - a huge tree, you cannot climb the tree.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the small clearing.\n");
  AddDetail(({"way","passable way","north"}),
    "The way leads north.\n");
  SetBright(20);
  AddExit("north",DFOREST("forest24"));
  AddItem(EATCORPSE("josie"),REFRESH_DESTRUCT);
  AddRoomCmd("climb",#'climb);
}
