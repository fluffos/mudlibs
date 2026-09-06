inherit "std/room";

#include <moving.h>
#include "path.h"

#define MIRROR_ROOM WHITEHOUSE("mirror_room1")

int rub(string str) {
  if ((!str) || (str!= "mirror")) return (int) notify_fail("Rub what?\n") && 0;
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
"as this one. There are some spots on it.\n");
  AddDetail(({"large square room","square room","large room","room",
	      "mirror room"}),#'IntLong);
  AddDetail(({"walls","wall"}),
    "Only the northern wall has something interesting: a mirror.\n");
  AddDetail(({"north wall","northern wall"}),"A mirror is placed there.\n");
  AddDetail(({"three sides","other three sides","sides","other sides"}),
    "Exits are there.\n");
  AddDetail(({"exits","exit"}),"You may leave through them.\n");
  AddDetail(({"spots","spot"}),
"You've seen cleaner mirrors.\n");
  AddExit("south","./cold_passage");
  AddExit("east","./cave2");
  AddExit("west","./winding_passage2");
  AddRoomCmd(({"wipe","clean","rub"}),#'rub);
}
