#include "path.h"
#include <combat.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("lamb");
  SetShort("a lamb");
  SetLong("A soft, cute baby lamb.\n");
  SetIds(({"lamb","sheep"}));
  SetAds(({"baby","little","cute","soft"}));
  SetLevel(5);
  SetHP(40);
  SetAlign(-10);
  SetAC(0);
  SetGender(0);
  SetWimpy(15);
  SetHands(({({"hooves",0,3}),({"mouth",0,4})}));
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a wool shield",
      P_LONG: "A shield made of lambs wool.\n",
      P_IDS: ({"shield","wool"}),
      P_ADS: ({"wool","lambs"}),
      P_ARMOUR_TYPE:AT_SHIELD,
      P_AC: 1,
      P_NUMBER_HANDS: 1,
      P_VALUE: 60,
      P_RESET_QUALITY: 100,
      P_SIZE:PSIZE_SMALL]));
}
