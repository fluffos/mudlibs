#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern. "
"A sign is fastened to one of the walls.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"cave","cavern","cold cave","cold cavern","dark cave",
  "dark cavern","dark and cold cavern","dark and cold cave"}),
QueryIntLong());
  AddDetail(({"floor","ground","ceiling","walls","wall"}),
"You see nothing special.\n");
  AddDetail("sign","Something is written on it.\n");
  AddReadMsg("sign","Number nine is free.\n");
  AddExit("east","./deep4");
  AddExit("west","./deep10");
  AddExit("north","./deep7");
}
