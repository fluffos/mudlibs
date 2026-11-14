// made by MagicTCS 18 mar 97
// part of the eatcorpse quest

#include <properties.h>
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

int enter(string str) {
  if (!str) { notify_fail("Enter what?\n"); return 0; }
  if (str=="bush" || str=="bushes") {
    write("The bushes are too dense to enter them.\n");
    show(this_player()->QueryName()+" tries to enter the bush, but fails.\n");
    return 1;
  }
  notify_fail("Enter what?\n"); 
  return 0;
}

create() {
  ::create();
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest. The trees are standing around you. Some\n"
    "bushes block the way to the north.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the east and west.\n");
  AddDetail(({"forest","green forest"}),
    "Some huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees look unclimbable.\n");
  AddDetail(({"bush","dense bush","bushes","dense bushes","some bushes",
    "some dense bushes"}),
    "They are bushes of wild increasing roses. Maybe you can pass the bushes?\n");
  SetBright(20);
  AddExit("east",DFOREST("forest32"));
  AddExit("west",DFOREST("forest02"));
  AddExit("northeast",DFOREST("forest31"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Barnabie",
       P_SHORT: "barnabie",
       P_IDS: ({"barnabie","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 69810,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: "The liquorice bear has a strong smile on his face.\n"
    ]) );
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("pass",#'enter);
}
