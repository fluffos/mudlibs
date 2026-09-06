#include "path.h"
#include <doors.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("in front of a door");
  SetIntLong("You're on a small piece of ground in front of a large door.\n");
  AddDetail("lock","An old and rusty lock.\n");
  AddExit("east","./coals2");
  AddDoor("west","./rroom2","huge door","It's a huge door with an old lock.\n",
    "pirate_rusty_key",DOOR_STATUS_LOCKED);
}
