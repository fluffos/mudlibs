// made by MagicTCS 17 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write("You try to climb the tree, but the branches are too high.\n");
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
    "A small path in the green forest. One path leads to the east and one to\n"
    "the northwest. The other ways are blocked by dense bushes.\n");
  AddDetail(({"small path","path"}),
    "There is one to the northwest and one to the east.\n");
  AddDetail(({"forest","green forest"}),
    "The forest consists of unnumbered huge trees and dense bushes.\n");
  AddDetail(({"tree","huge tree"}),
    "Well - a huge tree, but you can't climb the tree.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the small path.\n");
  AddDetail(({"bush","dense bush","rose bush"}),
    "It seems to be a wild increasing rose bush.");
  AddDetail(({"bushes","dense bushes"}),
    "The bushes have sharp thornes.\n");
  AddDetail(({"sharp thornes","sharp thorn","thorn","thornes"}),
    "The thorns are too sharp, so you don't want to ruin your clothes.\n");
  AddDetail(({"direction","directions","every directions"}),
    "You can walk to each direction.\n");
  SetBright(20);
  AddExit("east","./forest24");
  AddExit("northwest","./forest03");
  AddRoomCmd("climb",#'climb);
  // make the bears a little bit different :)
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Baerlie",
       P_SHORT: "bearlie",
       P_IDS: ({"bearlie","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 65200,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: 
       "A small baby bear. The body of this bear consists of liquorice only.\n"
    ]) );
}
