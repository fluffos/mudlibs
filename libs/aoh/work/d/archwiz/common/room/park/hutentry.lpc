#include "path.h"
#include <lock.h>

inherit "/std/room";

int do_open(string str) {
  if (!this_player()) return 0;
  if (str!="commode") return 0;
  return notify_fail(
"Nah... you don't want to touch Grandma's stuff. She won't be "
"happy about it.\n"),0;
}

create() {
  ::create();
  SetIntShort("The entry to grandma's hut");
  SetIntLong(
"You've entered a small, comfy hut. A carpet covers the floor and a small "
"commode stands at the southern wall.\n");
  AddDetail(({"small hut","hut","comfy hut","small, comfy hut","entry",
    "grandma's hut"}),#'IntLong);
  AddDetail(({"wall","southern wall"}),
"A small commode stands at the southern wall.\n");
  AddDetail("ceiling",
"It is painted white.\n");
  AddDetail(({"commode","small commode"}),"It's a small commode.\n");
  AddDetail("carpet","It is securely fasten to the ground so noone may fall over it.\n");
  SetIndoors(1);
  SetBright(20);
  AddRoomCmd("open",#'do_open);
  AddExit("west","./livroom");
  AddExit("north","./bedroom");
  AddExit("southeast","./pa4n4");
}
