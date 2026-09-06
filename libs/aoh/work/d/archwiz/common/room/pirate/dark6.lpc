#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a dark tunnel");
  SetIntLong(
"You are in a tunnel. The noises are getting louder.\n");
  AddDetail(({"tunnel","dark tunnel"}),QueryIntLong());
  AddDetail(({"walls","wall","ground","floor","ceiling"}),
"You see nothing special.\n");
  AddNoise(({"noise","noises"}),"They become louder.\n");
  SetIntNoise("It is loud down here.\n");
  SetIndoors(1);
  SetBright(-1);
  AddExit("west","./dark5");
  AddExit("east","./dark7");
}
