#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a stairway");
  SetIntLong("You're on a long stairway.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"stairways","stair","stairs","long stairway",
  "long stair","long stairs"}),QueryIntLong());
  AddDetail(({"walls","wall","floor","ceiling"}),
"You see nothing special.\n");
  AddExit("up","./downch1");
  AddExit("down","./downch3");
}
