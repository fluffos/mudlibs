// made by MagicTCS 23 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
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
  if (str=="hedge") {
    write("You cannot enter the hedge, but maybe you can pass it?\n");
    show(this_player()->QueryName()+
      " tries to enter a dense hedge, but fails.\n");
    return 1;
  }
  return 0;
}

int pass (string str) {
  if (!str) return 0;
  if (str=="hedge") {
    write("You discover a small slit in the hedge. You enter the small slit.\n");
    this_player()->move(DFOREST("forest71"),M_GO,"into the hedge");
    return 1;
  }
  return 0;
}

int goeast() {
  write("The way is blocked by a dense hedge.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("A green path");
  SetIntLong(
    "A path in the green forest.\n"
    "The way to the east is blocked by a dense hedge.\n");
  AddDetail(({"green path"}),
    "Yes, a green path inmids the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the northwest and south.\n");
  AddDetail(({"forest","green forest"}),
    "The forest consists of unnumbered huge trees and dense undergrowth.\n");
  AddDetail(({"tree","huge tree"}),
    "Well - a huge tree, but you can't climb the tree.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the path.\n");
  AddDetail(({"undergrowth","dense undergrowth"}),
    "It is very dense.\n");
  AddDetail(({"hedge","dense hedge"}),
    "There is a dense hedge, but there seems to be a way to the east.\n");
  AddDetail("way","The way leads into the hedge.\n");
  SetBright(20);
  AddExit("south",DFOREST("forest62"));
  AddExit("northwest",DFOREST("forest50"));
  AddExit("east",#'goeast);
  HideExit("east",1);
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("pass",#'pass);
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bloody",
       P_SHORT: "bloody",
       P_IDS: ({"bloody","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 65000,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: 
       "A liquorice bear, covered with blood.\n"
    ]) );
}
