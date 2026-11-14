#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cave");
  SetIntLong(
"You're in a cave with walls which seem to absorb the light. "
"There is a sign at one of the walls.\n");
  AddDetail(({"cave","large cave","dark cave","large dark cave"}),
QueryIntLong());
  AddDetail(({"walls","wall"}),
"They seem to absorb the light. It is difficult to see.\n");
  AddDetail(({"ground","floor","ceiling"}),
"You don't see anything special.\n");
  AddDetail("sign","There is something written on it.\n");
  AddReadMsg("sign",
"The one has said that the first man is blessed and the last is damned.\n");
  SetIndoors(1);
  SetBright(-10);
  AddExit("east","./incave");
  AddExit("southwest","./incave3");
}
