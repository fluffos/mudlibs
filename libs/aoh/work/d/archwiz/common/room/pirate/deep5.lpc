#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"cave","cavern","dark cave","dark cavern","cold cave",
  "cold cavern","dark and cold cavern","dark and cold cave"}),
QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You see nothing special.\n");
  AddExit("east","./deep2");
  AddExit("west","./deep9");
  AddExit("north","./deep8");
}
