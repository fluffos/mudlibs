#include "path.h"
#include <rooms.h>
#include <combat.h>

inherit "/std/room";

int do_climb(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Climb what?\n"),0;
  if (lower_case(str)!="menhir") return notify_fail(
    "You don't see such climbable thing here.\n"),0;
  write("You try to climb the menhir, but magically it vibrates and you fall down.\n");
  show_room(this_object(),
  this_player()->QueryName()+" tries to climb the menhir, but falls down.\n",({this_player()}));
  this_player()->Defend(1+random(4),DT_BLUDGEON,this_object());
  return 1;
}

create() {
  ::create();
  SetIntShort("A huge menhir");
  SetIntLong(
"You are in middle of the forest with a menhir to your left. "
"You see eyes glowing at you from the top of the menhir.\n");
  SetIndoors(0);
  AddDetail(({"forest","middle","trees","tree"}),
"You are somewhere in the middle of the forest.\n");
  AddDetail(({"eye","eyes"}),
"Those eyes probably belong to a wild animal.\n");
  AddDetail("menhir",
"The menhir stands right in front of you. You see eyes glowing "
"at you from the top of it.\n");
  AddRoomCmd("climb",#'do_climb);
  AddExit("west","./pa5n3");
  AddExit("east","./pa3n3");
  AddExit("south","./pa4n4");
  AddExit("north","./pa4n2");
  AddItem(MONSTER("park/lion"),REFRESH_HOME,2);
}
