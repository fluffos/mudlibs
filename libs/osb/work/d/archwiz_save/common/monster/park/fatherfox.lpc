#include "path.h"
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("fox");
  SetShort("a father fox");
  SetLong("Father fox sits in the sun, waiting for his couple.\n");
  AddId("fox");
  AddAdjective("father");
  SetLevel(3);
  SetHP(50);
  SetAlign(20);
  SetAC(1);
  SetWimpy(30);
  SetHands( ({ ({"mouth",0,4}),({"paws",0,2}) }) );
  SetSize(PSIZE_SMALL);
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "a very sharp tooth",
      P_LONG: "This tooth looks like a fox tooth.\n",
      P_IDS: ({"tooth"}),
      P_ADS: ({"fox","sharp","very sharp"}),
      P_VALUE: 30,
      P_WEIGHT: 25,
      P_WC: 3,
      P_RESET_QUALITY: 100,
      P_WEAPON_TYPE:WT_KNIFE,
      P_DAM_TYPE:DT_PIERCE,
      P_SIZE:PSIZE_SMALL]));
}
