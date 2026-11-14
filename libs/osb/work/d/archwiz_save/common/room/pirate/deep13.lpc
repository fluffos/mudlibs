#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern. "
"A sign is fastened to the wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"cave","cavern","dark cave","dark cavern","cold cave",
  "cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddDetail("sign","Something is written on it.\n");
  AddReadMsg("sign","Six we know, will try to crow.\n");
  AddExit("east","./deep13");
  AddExit("south","./deep14");
  AddExit("north","./deep12");
}
