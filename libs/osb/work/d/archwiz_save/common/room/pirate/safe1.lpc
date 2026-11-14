#include <doors.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("In front of a door.");
  SetIntLong(
"You are on a small piece of ground in front of a large door.\n");
  AddExit("east","./coals2");
  AddDoor("west","./rroom2","door",
"It's a huge door with an old lock.\n",
    "pirate_rusty_key",DOOR_STATUS_LOCKED);
}
