#include "path.h"
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("deer");
  SetShort("a mother deer");
  SetLong("Mother deer is waiting for her family.\n");
  SetGender(2);
  AddId("deer");
  SetAds(({"mother","female"}));
  SetLevel(4);
  SetHP(60);
  SetAlign(20);
  SetAC(4);
  SetHands( ({ ({"hooves",0,4}),({"mouth",0,6}) }));
  SetSize(PSIZE_NORMAL);
  SetWimpy(20);
}
