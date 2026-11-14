// made by MagicTCS 31 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write("You try to climb the tree, but there are no low branches left.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

create() {
  ::create();
  SetIntShort("A east-west path in the forest");
  SetIntLong(
    "A path in the green forest. Only some trees are standing around.\n");
  AddDetail(({"path","east-west path","east west path"}),#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the east and west - because it is a east-west path.\n");
  AddDetail(({"forest","green forest"}),
    "It is not really a forest - only some trees are standing around you.\n");
  AddDetail(({"tree","trees","huge tree","huge trees","some trees"}),
    "They are blocking the sunlight a little bit.\n");
  AddDetail(({"sunlight","sun"}),
    "The sunlight is blocked by the trees.\n");
  SetBright(0);
  AddExit("east",DFOREST("forest44"));
  AddExit("west",DFOREST("forest24"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bobby",
       P_SHORT: "bobby",
       P_IDS: ({"bobby","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 99810,
       P_GENDER: 1,
       P_ALIGN: -30,
       P_LONG: "A very heavy liquorice bear.\n"
    ]) );
  AddRoomCmd("climb",#'climb);
}
