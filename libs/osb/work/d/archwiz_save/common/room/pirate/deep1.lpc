#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a cavern deep below the surface.\n");
  AddDetail(({"cave","cavern"}),QueryIntLong());
  AddDetail("surface","It is far above you.\n");
  AddDetail(({"walls","wall","ground","floor","ceiling"}),
  "You see nothing special.\n");
  SetIndoors(1);
  SetBright(0);
  AddExit("northeast","./allexit");
  AddExit("west","./deep2");
}
