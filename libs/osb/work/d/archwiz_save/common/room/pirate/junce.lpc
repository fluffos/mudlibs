#include "path.h"
#include <moving.h>

inherit "/std/room";

int enter(string str) {
  if (!str) return (int) notify_fail("Enter what?\n") && 0;
  if (!this_player()) return 0;
  if (str!="outlet") return 0;
  write(
"You execute again the compress -f ...\n"
"As you enter, the way behind you is magically barred.\n");
  this_player()->move(PIRATE("rroom"),M_GO,"north");
  return 1;
}

create() {
  ::create();
  SetIntShort("a small stone chamber");
  SetIntLong(
"You're in a small chamber. An outlet is on the northern wall. "
"A one way sign is fastened above it.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"small chamber","chamber","stone chamber",
  "small stone chamber"}),QueryIntLong());
  AddDetail(({"stone","grey stone"}),"It is grey stone.\n");
  AddDetail(({"outlet","small outlet"}),
"Probably you could enter it.\n");
  AddDetail("sign","it points north and shows a arrow.\n");
  AddDetail(({"walls","wall","ceiling","floor","ground"}),
"You don't discover unknown things.\n");
  AddExit("west","./junc");
  AddExit("enter",#'enter);
  HideExit("enter",1);
}
