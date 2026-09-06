#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"cave","cavern","dark cave","cold cave","cold cavern",
  "dark cavern","dark and cold cavern","dark and cold cave"}),
QueryIntLong());
  AddDetail(({"walls","wall","ceiling","floor","ground"}),
"You see nothing special.\n");
  AddExit("east","./deep13");
  AddExit("south","./deep3");
  AddExit("west","./deep6");
}
