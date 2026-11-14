#include "path.h"
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("fox");
  SetShort("a baby fox");
  SetLong("A baby fox is playing in the bush.\n");
  AddId("fox");
  AddAdjective("baby");
  SetLevel(2);
  SetGender(0);
  SetHP(20);
  SetAlign(10);
  SetAC(0);
  SetSize(PSIZE_SMALL);
  SetWimpy(17);
  SetHands(({ ({"mouth",0,4}),({"paws",0,2})}));
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a foxtail",
      P_LONG: "The tail of a baby fox.\n",
      P_IDS: ({"tail","foxtail"}),
      P_ADS: ({"baby fox","fox"}),
      P_VALUE: 3,
      P_WEIGHT: 50,
      P_RESET_QUALITY:100,
      P_ARMOUR_TYPE:AT_AMULET,
      P_AC:0,
      P_SIZE:PSIZE_SMALL]));
}
