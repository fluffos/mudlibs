#include <properties.h>
#include <rooms.h>
inherit "std/npc";

create() {
  if (::create()) return 1;
  SetName("frog");
  SetShort("a green frog");
  SetLong("This is a cute little frog playing in the grass.\n");
  SetRace("frog");
  AddAdjective("green");
  AddAdjective("cute");
  AddAdjective("little");
  SetLevel(1);
  SetHands(({({"green legs",0,3})}));
  SetGender(0);
  SetNoGet("It hops away.\n");
  SetWimpy(10);
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT:"a frog skin",
      P_LONG:"The skin of a frog, quite slimy.\n",
      P_IDS:({"skin"}),
      P_ADS:({"frog","slimy"}),
      P_WEIGHT:20,
      P_VALUE:4]));
}
