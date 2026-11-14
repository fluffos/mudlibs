#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern. "
"There is a sign on the ground.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","something is written on it.\n");
  AddDetail(({"cave","cavern","dark cavern","dark cave",
  "cold cave","cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddReadMsg("sign","The fifth, of course, cannot be love.\n");
  AddExit("east","./deep3");
  AddExit("west","./deep7");
  AddExit("north","./deep6");
}
