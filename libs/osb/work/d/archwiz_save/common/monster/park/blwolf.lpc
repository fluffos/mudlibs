#include "path.h"
#include <combat.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("wolf");
  SetShort("a black wolf");
  SetLong("This is a black wolf, licking its fangs for your flesh.\n");
  AddId("wolf");
  AddAdjective("black");
  SetGender(0);
  SetAlign(-40);
  SetLevel(4);
  SetHP(40);
  SetAC(3);
  SetHands( ({ ({"fangs",0,5}),({"paws",0,2}) }) );
  SetWimpy(20);
  SetSize(PSIZE_SMALL);
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "sharp tooth",
      P_LONG: "This tooth looks like a very sharp wolf tooth.\n",
      P_IDS: ({"tooth","wolftooth","black_wolf\ntooth"}),
      P_ADS: ({"wolf","very sharp","sharp"}),
      P_SIZE:PSIZE_SMALL,
      P_VALUE: 30,
      P_WC: 3,
      P_RESET_QUALITY:100,
      P_WEAPON_TYPE:WT_KNIFE,
      P_DAM_TYPE:DT_PIERCE,
      P_WEIGHT: 25]));
}
