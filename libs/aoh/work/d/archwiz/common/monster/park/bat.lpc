#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "std/npc";

create() {
  if (::create()) return 1;
  SetName("bat");
  SetShort("a vampire bat");
  SetLong("This is a vampire bat, hanging from a tree.\n");
  SetRace("bat");
  AddAdjective("vampire");
  SetLevel(1);
  SetHands(({({"sharp teeth",0,4})}));
  SetGender(0);
  SetNoGet("It snaps at your fingers.\n");
  SetWimpy(5);
  SetAlign(-20);
  AddItem("/std/thing",REFRESH_REMOVE,
	  ([P_SHORT:"sharp teeth",
	  P_LONG:"The once belonged to a vampire bat.\n",
	  P_IDS:({"teeth"}),
	  P_ADS:({"vampire","sharp"}),
	  P_WEIGHT:75,
	  P_VALUE:20]));
}
