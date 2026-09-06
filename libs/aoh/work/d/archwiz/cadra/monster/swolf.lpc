/* Cadra 20-12-94 for the 'free_turanu' quest */
#include "path.h"
#include <combat.h>

inherit "/obj/spellmonster";

create() {
  if (::create()) return 1;
  SetName("sandwolf");
  SetShort("a huge sandwolf");
  SetLong(
"You face an ugly ochreyellow wolf. Its rough fur hangs around it. "
"It shows its bared teeth to you. You should be careful. The creature "
"looks not that dangerous, but very hungry.\n");
  SetAggressive(1);
  SetLevel(7);
  SetAC(3);
  SetIds(({"wolf","sandwolf"}));
  SetAds(({"sand","ochreyellow","yellow","ochre","ugly"}));
  AddSpell("bite","are bitten by a wolf. Its teeth go deep into your flesh.",
  "is bitten by a wolf.",10,20,DT_PIERCE);
  SetSpellChance(20);
  SetNeuter();
  SetHands(({}));
  SetRace("wolf");
  SetDex(20);
}
