#include <properties.h>
#include <rooms.h>

inherit "std/npc";

create() {
  if (::create()) return 1;
  SetName("grasshopper");
  SetShort("a green grasshopper");
  SetLong("This is a grasshopper.\n");
  SetRace("grasshopper");
  AddAdjective("green");
  SetLevel(1);
  SetHands(({({"legs",0,2})}));
  SetGender(0);
  SetNoGet("It jumps away from you.\n");
  SetAlign(10);
  SetWimpy(10);
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT:"a blade of grass",
      P_LONG:"A green blade of grass.\n",
	  P_IDS:({"blade","grass"}),
	  P_ADS:({"blade of","green"}),
	  P_WEIGHT: 1,
	  P_VALUE: 1]));
}
