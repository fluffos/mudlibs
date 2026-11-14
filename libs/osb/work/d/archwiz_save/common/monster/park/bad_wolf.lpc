#include "path.h"

#define MY_CORPSE OBJ("wolf_corpse")

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetRace("wolf");
  SetName("big bad wolf");
  SetShort("a big bad wolf");
  SetLong(
"This wolf looks well stuffed and really not hungry. He is that fat "
"right now that you feel sure he will stumble when fighting.\n");
  SetLevel(5);
  SetStr(9);
  SetDex(1);
  SetCon(10);
  SetCorpse(MY_CORPSE);
  SetHands(({({"mouth",0,8}),({"paws",0,2})}));
}
