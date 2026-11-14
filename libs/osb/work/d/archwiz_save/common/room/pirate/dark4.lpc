#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a dark tunnel");
  SetIntLong(
"You are in a tunnel. You hear soft noises from the east.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"tunnel","dark tunnel"}),QueryIntLong());
  AddDetail(({"walls","wall","ceiling","floor","ground"}),
"You see nothing special.\n");
  AddNoise(({"noise","noises"}),"They are louder in the east.\n");
  SetIntNoise("It is loud. Noises come from east.\n");
  AddExit("west","./dark3");
  AddExit("east","./dark5");
}
