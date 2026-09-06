#include <combat.h>
#include <properties.h>

inherit "/std/weapon";

create() {
  ::create();
  SetStandard(WT_KNIFE,1,PSIZE_NORMAL);
  SetShort("a hunting knife");
  SetLong(
"This is a sharp hunting knife. You feel that this is no weapon to "
"fight with, though. It is only there for cutting the hunted animal "
"in pieces after the hunt.\n");
  SetMagic(1);  // Just because it is ONLY useable with the wolfs corpse
                // as the hunter tells one
  SetResetQuality(100);
  SetAds(({"hunting","small","sharp"}));
  SetIds(({"knife","hunt\nknife"}));
}
