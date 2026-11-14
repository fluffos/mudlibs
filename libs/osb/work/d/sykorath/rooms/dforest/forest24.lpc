// made by MagicTCS 17 mar 97
// part of the eatcorpse quest
// TODO: Replace the names on the sign with OSB names.

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
  SetIntShort("A small path");
  SetIntLong(
    "A small path in the green forest. You can walk to every direction.\n"
    "A sign stands here.\n");
  AddDetail(({"small path","path"}),#'QueryIntLong);
  AddDetail(({"forest","green forest"}),
    "The forest consists of unnumbered huge trees.\n");
  AddDetail(({"tree","huge tree"}),
    "Well - a huge tree, you cannot climb the tree.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the small path.\n");
  AddDetail(({"direction","directions","every directions"}),
    "You can walk to each direction.\n");
  AddDetail(({"sign","small sign"}),
    "The small sign has four arms that are pointing to each direction.\n"
    "You can read the arms.\n");
  AddDetail(({"arm","arms","arm of sign","arms of sign"}),
    "You can read the arms.\n");
  AddReadMsg(({"arms","arm","sign","small sign"}),
    "Which arm do you want to read - the one to the north, east, south or\n"
    "west?\n");
  AddReadMsg(({"north arm","arm north", "arm to the north"}), 
    "You read: \"North - 150 miles.\"\n");
  AddReadMsg(({"east arm","arm east", "arm to the east"}),
    "You read: \"East - 35 miles.\"\n");
  AddReadMsg(({"south arm","arm south", "arm to the south"}),
    "You read: \"South - 40 miles.\"\n");
  AddReadMsg(({"west arm","arm west", "arm to the west"}),
    "You read: \"West - 148 miles.\"\n");
  SetBright(20);
  AddExit("north",DFOREST("forest23"));
  AddExit("west",DFOREST("forest14"));
  AddExit("east",DFOREST("forest34"));
  AddExit("south",DFOREST("forest25"));
  AddRoomCmd("climb",#'climb);
}
