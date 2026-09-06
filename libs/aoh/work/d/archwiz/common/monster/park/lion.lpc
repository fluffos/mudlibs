#include "path.h"
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("lion");
  SetLong("This is a mountain lion on his pre-dinner-siesta.\n");
  AddId("lion");
  AddAdjective("mountain");
  SetGender(1);
  SetRace("lion");
  SetLevel(4);
  SetAC(4);
  SetHP(40);
  SetAlign(-10);
  SetSize(PSIZE_NORMAL);
  SetHands(({ ({"mouth",0,4}),({"paws",0,3})}));
  SetWimpy(10);
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a lionsskin leather armour",
      P_LONG: "The skin of a lion, that can be worn as armour.\n",
      P_IDS: ({"skin","armour"}),
      P_ADS: ({"lionsskin","skin","leather"}),
      P_VALUE: 80,
      P_AC: 3,
      P_SIZE:PSIZE_NORMAL,
      P_RESET_QUALITY:100,
      P_WEIGHT: 2000,
      P_ARMOUR_TYPE:AT_MAIL]));
}
