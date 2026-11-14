#include "path.h"
#include <rooms.h>
#include <properties.h>
#include <combat.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("fox");
  SetShort("a mother fox");
  SetLong("Mother fox rests from cleaning up.\n");
  AddId("fox");
  SetAds(({"mother","female"}));
  SetGender(2);
  SetLevel(3);
  SetHP(40);
  SetAlign(20);
  SetAC(3);
  SetWimpy(20);
  SetHands( ({ ({"right paw",0,3}),({"mouth",0,5})}));
}
