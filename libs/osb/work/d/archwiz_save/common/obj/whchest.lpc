inherit "/obj/chest";

#include <properties.h>
#include <rooms.h>
#include "../path.h"

create() {
  ::create();
  seteuid(getuid(this_object()));
  SetShort("wooden chest");
  SetLong("A heavy wooden chest with iron bands.\n");
  SetIds(({"chest"}));
  SetAds(({"a","heavy","wooden","treasure"}));
  SetLockState(LOCK_LOCKED);
  SetKeyIds(({"whchest"}));
  SetNoGet("The chest is much too heavy.\n");
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT:"necklace",
      P_LONG:"A beautiful necklace.\n",
      P_IDS:({"necklace","angelas_necklace"}),
      P_ADS:({"beautiful"}),
      P_WEIGHT:20,
      P_VALUE:300]));
}
