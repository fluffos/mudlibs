#include <rooms.h>
#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a path around a dark tower");
  SetIntLong(
"You're on a small path which leads around a shimmering tower. Some small "
"rocks are lying here and to the north you see the center of Nightfall city.\n");
  AddDetail(({"small path","path"}),QueryIntLong());
  AddDetail(({"shimmering tower","tower","administration tower"}),
"It is the administration tower of Nightfall.\n");
  AddDetail(({"rocks","rock"}),
"There are rocks covering the ground.\n");
  AddDetail(({"ground","floor"}),"It is covered by rocks.\n");
  AddDetail(({"center","centre","nightfall city","city"}),
"Go and investigate it.\n");
  SetIndoors(0);
  AddExit("northwest","./backtower");
  AddExit("south","./arounde2");
  AddItem(MONSTER("buggybug"),REFRESH_DESTRUCT);
}
