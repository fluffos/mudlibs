#include "path.h"
#include <moving.h>

inherit "/std/room";

int west() {
  write("A voice whispers in your mind: 'speak' the answer to the following "
"riddle to gain access to the west.\n");
  say("A voice whispers in your mind: 'speak' the answer to the following "
"riddle to gain access to the west.\n");
  write("In the morning it has 4 legs, in the noon 2 and in the evening 3.\n");
  say("In the morning it has 4 legs, in the noon 2 and in the evening 3.\n");
  write("What's this ?\n");
  say("What's this ?\n");
  return 1;
}

int sp(string str) {
  if ((str!="man") && (str!="men") && (str!="human")) 
    return (int) notify_fail("WRONG.\n") && 0;
  write("Correct !\n");
  this_player()->move(PIRATE("dx1"),M_GO,"west");
  return 1;
}

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"cave","cavern","dark cave","dark cavern","cold cavern",
  "cold cave","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddRoomCmd("speak",#'sp);
  AddRoomCmd("answer",#'sp);
  AddExit("east","./deep11");
  AddExit("west",#'west);
  AddExit("north","./deep8");
}

