// made by MagicTCS 18 mar 97
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
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest. The trees are standing around you. You have a\n"
    "bad feeling looking at them.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the east and south.\n");
  AddDetail(({"forest","green forest"}),
    "Many unnumbered huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "Someone has carved a sign into the tree. You can read it.\n");
  AddDetail("sign","You can read it.\n");
  AddReadMsg(({"tree","trees","huge tree","huge trees"}),
    "How about reading the sign instead?\n");
  AddReadMsg("sign","You read: Jolly loves Joey and Joey loves Jolly.\n");
  SetBright(20);
  AddExit("east",DFOREST("forest22"));
  AddExit("south",DFOREST("forest03"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bambie",
       P_SHORT: "bambie",
       P_IDS: ({"bambie","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 69810,
       P_GENDER: 2,
       P_ALIGN: -30,
       P_AGGRESSIVE: 1,
       P_LONG: "A fierce liquorice bear.\n"
    ]) );
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bimboline",
       P_SHORT: "bimboline",
       P_IDS: ({"bimboline","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 55060,
       P_GENDER: 2,
       P_AGGRESSIVE: 1,
       P_LONG: "A beautiful liquorice bear. Small, but beautiful!\n",
    ]) );
  AddRoomCmd("climb",#'climb);
}
