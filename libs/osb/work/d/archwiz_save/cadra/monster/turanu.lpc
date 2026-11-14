/* Cadra 29-12-94 for the free_turanu quest */
#include "path.h"

inherit "/std/npc";

int canflee,amfree;

SetICanFlee(int i) { return canflee=1; }
QueryICanFlee() { return canflee; }

SetIamFree(int i) { return amfree=1; }
QueryIamFree() { return amfree; }

create() {
  if (::create()) return 1;
  SetName("Turanu");
  SetShort("A poor faery");
  SetLong(
"This faery looks really sad and hopeless. Are you the one to help him?\n");
  SetMale();
  SetRace("faery");
  SetLevel(1);
  SetHands(({({"left hand",0,2}),({"right hand",0,2})}));
  SetAC(1);
  SetIds(({"faery","turanu","turanutofree"}));
  SetAds(({"a","poor","little","sad","hopeless"}));
  canflee=0;
  amfree=0;
}
