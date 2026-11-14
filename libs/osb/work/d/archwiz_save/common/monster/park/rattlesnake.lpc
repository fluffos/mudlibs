#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "/std/npc";

create(){
  if (::create()) return 1;
  SetName("snake");
  SetShort("a rattlesnake");
  SetLong("This is a rattlesnake, staring at you.\n");
  AddId("rattlesnake"),
  AddAdjective("rattle");
  SetLevel(3);
  SetCon(1);
  SetAlign(-30);
  SetHands(({({"its fangs",0,5})}));
  SetWimpy(10);
  AddItem("/std/thing",REFRESH_REMOVE,
	  ([P_SHORT:"a snake skin",
	  P_LONG:"A skin of a rattlesnake.\n",
	  P_IDS:({"skin"}),
	  P_ADS:({"snake","rattlesnake"}),
	  P_WEIGHT:200,
	  P_VALUE:100]));
}
