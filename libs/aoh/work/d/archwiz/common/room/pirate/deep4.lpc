#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern. "
"There is a sign on the wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","There is something written on it.\n");
  AddDetail(({"cave","cavern","dark cave","dark cavern",
  "cold cave","cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You see nothing special.\n");
  AddReadMsg("sign",
"The last you see is number ten, they cannot be called manly men.\n");
  AddExit(({"east","west"}),"./deep4");
  AddExit("north","./deep6");
}
