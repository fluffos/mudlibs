// made by MagicTCS 17 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int pray(string str) {
  if (str) { notify_fail("Use a simple pray.\n"); return 0; }
  write("You want to pray near a broken and old altar? How stupid!\n"
    "Better search another altar or a church.\n");
  show(this_player()->QueryName()+" tries to pray, but fails.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("A clearing");
  SetIntLong(
    "A clearing inmids the green forest. A old and broken altar can be seen\n"
    "here. Maybe this is one of the old ceremonial places of the gnomes?\n"
    "There is only a way back to west.\n");
  AddDetail("clearing",#'QueryIntLong);
  AddDetail(({"green path"}),
    "Yes, a green path inmids the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the north, east and southeast.\n");
  AddDetail(({"forest","green forest"}),
    "The forest consists of unnumbered huge trees and dense undergrowth.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees are concentrate the magic to this place.\n");
  AddDetail(({"undergrowth","dense undergrowth"}),
    "You cannot enter it.\n");
  AddDetail(({"altar","old altar","broken altar","old and broken altar"}),
    "The altar is old and broken. Useless for normal livings.\n");
  AddDetail(({"place","ceremonial place"}),
    "Just like one of the old places, where the gnomes met themself.\n");
  AddDetail(({"way","way back"}),"It leads to the west.\n");
  SetBright(20);
  AddExit("west","./forest03");
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Barnie",
       P_SHORT: "barnie",
       P_IDS: ({"barnie","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 71000,
       P_GENDER: 1,
       P_LONG: "A huge bear, consisting of liquorice.\n"
    ]) );
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Babsie",
       P_SHORT: "babsie",
       P_IDS: ({"babsie","bear"}),
       P_ADS: ({"liquorice"}),
       P_GENDER: 2,
       P_WEIGHT: 63300,
       P_LONG: "Yes another liquorice bear.\n"
    ]) );
  AddRoomCmd("pray",#'pray);
}
