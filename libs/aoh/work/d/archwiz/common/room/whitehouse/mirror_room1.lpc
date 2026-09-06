inherit "std/room";
#include <moving.h>
#include "path.h"

#define MIRROR_ROOM WHITEHOUSE("mirror_room2")

int rub(string str) {
  if ((!str) || (str != "mirror")) 
    return (int) notify_fail("Rub what?\n") && 0;
  write("There is a rumble from deep within the earth and the room shakes.\n");
  return this_player()->move(MIRROR_ROOM,M_GO,"to nowhere");
}

create() {
  ::create();
  SetIntShort("Mirror Room");
  SetIntLong(
"You are in a large square room with tall ceilings. On the north "
"wall is an enormous mirror which fills the entire wall. There are "
"exits on the other three sides of the room.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"enormous mirror","mirror"}),
"You see your own reflection and a room that looks just the same "
"as this one. The mirror has some spots on it.\n");
  AddDetail(({"room","square room","large room","large square room"}),
    #'IntLong);
  AddDetail(({"ceilings","ceiling","tall ceilings","tall ceiling"}),
    "You put your head into your neck and look up. You see nothing of interest.\n");
  AddDetail(({"north wall","northern wall"}),
    "There's a mirror at the northern wall.\n");
  AddDetail(({"walls","wall"}),
    "The only special thing is that mirror at the northern wall.\n");
  AddDetail(({"exits","exit"}),
    "You may leave through the exits.\n");
  AddDetail(({"sides","other sides","three sides","other three sides"}),
    "There are exits.\n");
  AddDetail(({"spot","spots"}),
"You've seen cleaner mirrors.\n");
  AddExit("south","./narrow_passage");
  AddExit("east","./cave1");
  AddExit("west","./winding_passage1");
  AddRoomCmd(({"rub","wipe","clean"}),#'rub);
}
