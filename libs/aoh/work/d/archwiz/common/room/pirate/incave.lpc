#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a dusty cave");
  SetIntLong(
"You're in a large dusty cave. You see an exit to the east. "
"The cave continues to the west.\n");
  AddDetail(({"cave","large cave","dusty cave","large dusty cave"}),
QueryIntLong());
  AddDetail(({"exit","entrance"}),
"It seems to be the entrance into this cave.\n");
  AddDetail(({"walls","wall"}),
"There is some dried salt on the walls. If there is high flood this cave "
"probably could become an underwater cave.\n");
  AddDetail(({"salt","dried salt"}),
"There is lot of sand between it. It is of no use to get it.\n");
  AddDetail(({"sand","lot of sand"}),
"Sand and dried salt cover the walls.\n");
  AddDetail(({"dust","normal dust","dusty dust"}),
"It covers the ground.\n");
  AddDetail(({"ground","floor","ceiling"}),"It is dry.\n");
  SetIndoors(1);
  SetBright(0);
  AddExit("east","./beach2");
  AddExit("west","./incave2");
}
