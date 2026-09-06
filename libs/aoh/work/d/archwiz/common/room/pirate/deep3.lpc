#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark an cold cavern. "
"There is a sign at the wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","There is something written on it.\n");
  AddDetail(({"cave","cavern","dark cave","dark cavern",
  "cold cave","cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddReadMsg("sign","And number two is never true.\n");
  AddExit("north","./deep12");
  AddExit("south","./deep2");
  AddExit("east","./deep3");
}
