#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong(
"You're in a dark and cold cavern.\n");
  AddDetail(({"cave","cavern","old cave","old cavern","dark cave",
  "dark cavern","old and dark cavern","old and dark cave"}),QueryIntLong());
  AddDetail(({"walls","wall","ceiling","floor","ground"}),
"You see nothing special.\n");
  AddExit("west","./deep4");
  AddExit("north","./deep3");
  AddExit("south","./deep11");
  AddExit("east","./deep1");
}
