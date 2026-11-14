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

int enter (string str) {
  if (!str) return 0;
  if (str=="undergrowth" || str=="forest" || str=="dense undergrowth") {
    write("The undergrowth is too dense to enter it.\n");
    show(this_player()->QueryName()+
      " tries to enter the undergrowth, but fails.\n");
    return 1;
  }
  return 0;
}

create() {
  ::create();
  SetIntShort("A green path");
  SetIntLong(
    "A green path in the green forest. There are three different pathes.\n"
    "The other ways are blocked by dense undergrowth.\n");
  AddDetail(({"green path"}),
    "Yes, a green path inmids the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the north, east and southeast.\n");
  AddDetail(({"forest","green forest"}),
    "The forest consists of unnumbered huge trees and dense undergrowth.\n");
  AddDetail(({"tree","huge tree"}),
    "Well - a huge tree, but you can't climb the tree.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the small path.\n");
  AddDetail(({"undergrowth","dense undergrowth"}),
    "You cannot enter it.\n");
  SetBright(20);
  AddExit("southeast",DFOREST("forest14"));
  AddExit("north",DFOREST("forest02"));
  AddExit("east",DFOREST("forest13"));
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Burlie",
       P_SHORT: "burlie",
       P_IDS: ({"burlie","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 65000,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: 
       "A liquorice bear, that means the whole body consists of liquorice.\n"
    ]) );
}
