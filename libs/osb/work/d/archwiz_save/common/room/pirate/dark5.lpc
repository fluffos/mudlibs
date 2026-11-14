#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a dark tunnel");
  SetIntLong(
"You're in a tunnel. The noises are getting louder.\n");
  AddDetail(({"tunnel","dark tunnel"}),QueryIntLong());
  AddDetail(({"walls","wall","ground","floor","ceiling"}),
"You see nothing special.\n");
  SetIntNoise("It is loud in here.\n");
  AddNoise(({"noise","noises"}),"It is extremely loud here.\n");
  SetIndoors(1);
  SetBright(0);
  AddExit("west","./dark4");
  AddExit("east","./dark6");
}
