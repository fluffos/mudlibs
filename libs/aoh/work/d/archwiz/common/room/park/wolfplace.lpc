#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Deep between the bushes");
  SetIntLong(
"You are not sure where you are now, but you feel that you cannot be far "
"away from places known to you. This must be the home of the big bad wolf.\n");
  SetIndoors(1);
  SetBright(30);
  SetTPort(TPORT_NO);
  AddExit("out","./pa5n1");
  AddItem(MONSTER("park/bad_wolf"),REFRESH_HOME);
}
