#include "path.h"
#include <moving.h>

inherit "/std/room";

int enter(string str) {
  if (!str) return (int) notify_fail("Enter what?\n");
  if (str!="outlet") return 0;
  if (!this_player()) return 0;
  write(
"You execute again the compress ... Hope this was a wise choice...\n"
"As you enter, the way behind you is magically barred.\n");
  this_player()->move(PIRATE("balcon"),M_GO,"north");
  return 1;
}

create() {
  ::create();
  SetIntShort("a small stone chamber");
  SetIntLong(
"You're in a small stone chamber. An outlet is in the northern wall. "
"A sign reads: No return beyond this point.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"chamber","room","small room","small chamber",
  "stone chamber","small stone chamber","small stone room"}),
QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You discover no unknown things.\n");
  AddDetail(({"outlet","small outlet"}),
"Perhaps it will be possible to enter it?\n");
  AddDetail("northern wall","There is a small outlet in it.\n");
  AddDetail("sign","Something is written on it.\n");
  AddReadMsg("sign","No return beyond this point.\n");
  AddExit("east","./junc");
  AddExit("enter",#'enter);
  HideExit("enter",1);
}
