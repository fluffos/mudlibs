// made by MagicTCS 31 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  notify_fail("Where do you want to climb?\n");
  return 0;
}

create() {
  ::create();
  SetIntShort("A clearing");
  SetIntLong(
    "A clearing inmids the green forest.\n"
    "There are some ways here.\n");
  AddDetail("clearing",#'QueryIntLong);
  AddDetail(({"green path"}),
    "Yes, a green path inmids the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the north, northeast and northwest.\n");
  AddDetail(({"forest","green forest"}),
    "The forest consists of unnumbered huge trees and some clearings like\n"
    "this one.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees are to small to climb.\n");
  AddDetail(({"way","some ways","ways"}),
    "They lead to the west, northwest and northeast.\n");
  SetBright(20);
  AddExit("west",DFOREST("forest34"));
  AddExit("northwest",DFOREST("forest33"));
  AddExit("northeast",DFOREST("forest62"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Briztdelt",
       P_SHORT: "briztdelt",
       P_IDS: ({"briztdelt","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 71000,
       P_GENDER: 1,
       P_LONG: "A bear, consisting of liquorice with a very crazy name.\n"
    ]) );
  AddRoomCmd("climb",#'climb);
}
