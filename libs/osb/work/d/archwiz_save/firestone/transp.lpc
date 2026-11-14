#include <rooms.h>;
#include <moving.h>
#include "path.h"

inherit "/std/room";

int repair;

reset() {
  ::reset();
  repair=0;
}

init_tell() {
  call_out("operator", 5);
}

operator() {
  tell_room(this_object(),
   "One Operator says confused: You are not the captain!\n");
}

b_beam(string str) {
  object ob;
  mixed dir;
  string d;

  if (!repair)
    return notify_fail(
"The Operator says to you: We can't do this, because the transporter\n"
"  is out of order - no energy.\n");
  if (!str)
     return notify_fail("Beam to where?\n");
  if (str=="down") dir=FIRESTONE("entr");
  else {
  if (sscanf(str, "to %s",d)!=1)
    return notify_fail("Beam to where?\n");
  switch(d) {
    case "down": dir=FIRESTONE("entr"); break;
    case "shop": dir=CITY("shop"); break;
    case "kirk":
    case "base": dir=FIRESTONE("r_kirk"); break;
   default: dir=CITY("church");
   }
  }
  if (!this_player()) return 0;
  return this_player()->move(dir,M_SPECIAL,({
    "becomes indistinct and disappears",
    "arrives in a puff of smoke",
    "are beamed away"}));
}

repair_trans() { repair=1; }

int do_ask(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Ask whom about what?\n"),0;
  if (strstr(str,"operator")!=-1) {
    write("The operators are much too busy to talk to you.\n");
    return 1;
    }
  return notify_fail("You feel too busy to ask and waste time.\n"),0;
}

create() {
  ::create();
  SetIntShort("This is the transporter room.");
  SetIntLong(
"This is the transporter room of the old spaceship Enterprise.\n"
"You see two operators staring at you. They seem to be very "
"astonished at you.\n"
"At the wall you see a board with transporter instructions.\n\n");
  AddDetail(({"operator","operators","two operators"}),
"The operators are really busy.\n");
  AddRoomCmd("beam",#'b_beam);
  AddRoomCmd("ask",#'do_ask);
  AddExit("east","./r_t1");
  AddExit("west","./rescue");
  AddItem(FIRESTONE("instr"),REFRESH_REMOVE);
  reset();
}
