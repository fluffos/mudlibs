#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern. "
"There is a sign at one of the walls.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","You should try to read it.\n");
  AddDetail(({"cave","cavern","dark cavern","dark cave",
  "cold cave","cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddReadMsg("sign","And this is the first, it quenches thirst.\n");
  AddExit(({"north","east"}),"./deep14");
  AddExit("west","./deep11");
}
