#include "path.h"
#include <moving.h>

inherit "/std/room";

int north() {
  write("A voice whispers: ' 'speak' the answer to the following riddle to gain "
"access to the room to the north. "
"The more you take from it, the bigger it gets. "
"What's that?\n");
  return 1;
}

int sp(string str) {
   if (!str) return (int) notify_fail(
     "Speak <text>\n") && 0;
   if (str!="hole")  return (int) notify_fail(
     "WRONG.\n") && 0;
   if (!this_player()) return 0;
   write("Correct !\n");
   this_player()->move(PIRATE("dx2"),M_GO,"north");
   return 1;
}

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"dark cave","dark cavern","cave","cavern","cold cave",
  "cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You see nothing special.\n");
  AddRoomCmd("speak",#'sp);
  AddRoomCmd("answer",#'sp);
  AddExit("east","./deep12");
  AddExit("south","./deep8");
  AddExit("north",#'north);
}
