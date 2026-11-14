/* Cadra 29-12-94 for the free_turanu quest */
#include "path.h"
#include <combat.h>

inherit "/obj/spellmonster";

create() {
  if (::create()) return 1;
  SetName("dark shadow");
  SetShort("A dark shadow");
  SetLong("You face the pure darkness.\n");
  SetRace("shadow");
  SetNeuter();
  SetAttribute("MagicDefence",35);
  SetAlign(-600);
  SetLevel(20);
  SetHP(250);
  AddDefence(DT_COLD,60);
  AddDefence(DT_ACID,35);
  AddDefence(DT_PIERCE,50);
  AddDefence(DT_SLASH,50);
  SetAC(8);
  AddSpell("cold","are hit by a cold blow.","is hit by a cold blow.",10,10,DT_COLD);
  SetSpellChance(10);
  SetHands(({({"left wing",0,15}),({"right wing",0,16})}));
  SetIds(({"shadow"}));
  SetAds(({"deep","dark","a"}));
}
