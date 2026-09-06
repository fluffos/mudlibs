// made by MagicTCS 20 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write(
    "You try to climb the tree, but you see no low branches.\n");
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
    "A path in the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail("way","There is a way leading southeast.\n");
  AddDetail(({"pathes","different pathes"}),
    "You can go to the southwest and northeast.\n");
  AddDetail(({"forest","green forest"}),
    "Some huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees look unclimbable.\n");
  SetBright(20);
  AddExit("northeast",DFOREST("forest40"));
  AddExit("southwest",DFOREST("forest22"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Baerbel",
       P_SHORT: "baerbel",
       P_IDS: ({"baerbel","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 53850,
       P_GENDER: 2,
       P_LONG: "A simple liquorice bear looking at you.\n"
    ]) );
  AddRoomCmd("climb",#'climb);
}
