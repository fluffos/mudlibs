#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern.\n");
  AddDetail(({"cave","cavern","dark cave","dark cavern","cold cave",
  "cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"floor","ground","ceiling","walls","wall"}),
"You see nothing special.\n");
  AddExit("east","./deep8");
  AddExit("west","./outx");
  AddExit("north","./deep10");
}
