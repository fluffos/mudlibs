// made by MagicTCS 19 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write(
    "You try to climb the tree, but you see no way to the first lowest\n"
    "branch.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

int go_nw() {
  write("You are pierced by the thornes.\n");
  this_player()->DoDamage(3,DT_PIERCE);
  this_player()->move(DFOREST("forest21"),M_GO);
  return 1;
}

int enter(string str) {
  if (!str) { notify_fail("Enter what?\n"); return 0; }
  if (str=="bush" || str=="bushes") {
    return go_nw();
  }
  notify_fail("Enter what?\n"); 
  return 0;
}

create() {
  ::create();
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest. Trees are all around you. There is a bush\n"
    "that is blocking the way to the northwest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the northwest, west and southwest.\n");
  AddDetail(({"forest","green forest"}),
    "Trees, trees, trees - because it is a forest!\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees are really huge.\n");
  AddDetail(({"bush","dense bush"}),
    "You can pass the bush, but the bush has sharp thornes.\n");
  AddDetail(({"bushes","dense bushes","some bushes",
    "some dense bushes"}),
    "There is only one bush here.\n");
  AddDetail(({"thornes","sharp thornes","thorn","sharp thorn"}),
    "They will pierce you!\n");
  SetBright(20);
  AddExit("west",DFOREST("forest22"));
  AddExit("northwest",#'go_nw);
  AddExit("southwest",DFOREST("forest23"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bundy",
       P_SHORT: "bundy",
       P_IDS: ({"bundy","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 67810,
       P_GENDER: 1,
       P_AGGRESSIVE: 1,
       P_LONG: "It is one of the liquorice bears.\n"
               "You heared his name somewhere? But where?.\n"
    ]) );
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("pass",#'enter);
}
