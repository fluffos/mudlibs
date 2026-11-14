// made by MagicTCS 20 mar 97
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

create() {
  ::create();
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest. The trees are standing around you. Some\n"
    "bushes block the way to the north.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail("way","There is a way leading southeast.\n");
  AddDetail(({"pathes","different pathes"}),
    "You can go to the southeast and west.\n");
  AddDetail(({"forest","green forest"}),
    "Some huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees look unclimbable.\n");
  AddDetail(({"bush","dense bush","bushes","dense bushes","some bushes",
    "some dense bushes"}),
    "They are bushes of wild increasing roses.\n");
  AddDetail(({"rose","roses","wild rose","wild roses"}),
    "They are red roses.\n");
  SetBright(20);
  AddExit("west",DFOREST("forest40"));
  AddExit("southeast",DFOREST("forest61"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bernully",
       P_SHORT: "bernully",
       P_IDS: ({"bernully","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 68850,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: "The liquorice bear has a strong smile on his face.\n"
    ]) );
  AddRoomCmd("climb",#'climb);
}
