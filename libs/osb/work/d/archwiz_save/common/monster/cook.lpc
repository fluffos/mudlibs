/* Cadra for the free_turanu quest */
#include "path.h"
#include <combat.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("palace cook");
  SetShort("The cook of the palace");
  SetLong(
"This man looks somehow strange. Dressed completely in white with a large "
"hat on his head.\n");
  SetHands(({({"left hand",0,20}),({"right hand",0,20})}));
  SetLevel(21);
  SetHP(500);
  SetAC(10);
  SetAttribute("MagicDefence",60);
  AddDefence(DT_FIRE,30);
  SetIds(({"cook","man","human"}));
  SetAds(({"palace","the","a"}));
  SetRace("human");
  SetMale();
}
