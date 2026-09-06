#include "path.h"
#include <rooms.h>
#include <combat.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("dog");
  SetShort("a wild dog");
  SetLong("The wild dog is chewing some bones.\n");
  AddId("dog");
  SetRace("dog");
  AddAdjective("wild");
  SetLevel(3);
  SetHP(30);
  SetAlign(-30);
  SetAC(1);
  SetHands( ({ ({"mouth",0,5}),({"paws",0,2}) }) );
  SetWimpy(25);
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
	([P_SHORT: "a sharp tooth",
	  P_LONG: "This looks like a very sharp tooth.\n",
	  P_WEAPON_TYPE:WT_KNIFE,
	  P_DAM_TYPE:DT_PIERCE,
	  P_WC: 2,
	  P_RESET_QUALITY:100,
	  P_VALUE: 30,
	  P_WEIGHT:25,
	  P_IDS: ({"tooth"}),
	  P_ADS: ({"dog","sharp"})]));
}
