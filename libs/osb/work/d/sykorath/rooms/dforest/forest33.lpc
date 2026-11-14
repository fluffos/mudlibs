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
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the northeast and southeast.\n");
  AddDetail(({"forest","green forest"}),
    "Many unnumbered huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "Huge, green, unnumbered, nothing special.\n");
  SetBright(20);
  AddExit("northeast",DFOREST("forest42"));
  AddExit("southeast",DFOREST("forest44"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bruzel",
       P_SHORT: "bruzel",
       P_IDS: ({"bruzel","bear"}),
       P_ADS: ({"liquorice","fierce","huge"}),
       P_WEIGHT: 75810,
       P_GENDER: 1,
       P_ALIGN: -60,
       P_AGGRESSIVE: 1,
       P_LONG: "A huge liquorice bear looking fiercely at you.\n"
    ]) );
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bruzella",
       P_SHORT: "bruzella",
       P_IDS: ({"bruzella","bear"}),
       P_ADS: ({"liquorice","little"}),
       P_WEIGHT: 57060,
       P_GENDER: 2,
       P_LONG: "A little liquorice bear!\n",
    ]) );
  AddRoomCmd("climb",#'climb);
}
