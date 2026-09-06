#include "path.h"
#include <rooms.h>
#include <combat.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("longhorn");
  SetShort("a texas longhorn");
  SetLong("A longhorn with sad eyes.\n");
  SetIds(({"cow","loghorn","bull"}));
  SetAds(({"texas","sad"}));
  SetSize(PSIZE_NORMAL);
  SetLevel(5);
  SetHP(50);
  SetAlign(50);
  SetAC(6);
  SetHands( ({ ({"horns",0,7}),({"hooves",0,4}) }));
  SetWimpy(10);
  SetSize(PSIZE_NORMAL);
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "long horn",
      P_LONG: "Obviously the horn of a longhorn.\n",
      P_WC: 4,
      P_WEAPON_TYPE:WT_KNIFE,
      P_DAM_TYPE:DT_PIERCE,
      P_WEIGHT: 5000,
      P_VALUE: 80,
      P_SIZE:PSIZE_NORMAL,
      P_RESET_QUALITY:100]));
}
