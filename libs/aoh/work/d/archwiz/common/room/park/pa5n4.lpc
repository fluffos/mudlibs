#include "path.h"

inherit "/std/room";

int do_open(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("What do you try to open?\n"),0;
  if ((str!="gate") && (str!="closed gate")) return
    notify_fail("You don't see that here.\n"),0;
  write("The gate is securely locked.\n");
  return 1;
}

int do_unlock(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("What do you want to unlock?\n"),0;
  str=lower_case(str);
  if ((str!="gate") && (str!="closed gate") && (str!="locked gate")
    && (str!="gate with key")) return
    notify_fail("You can't unlock that here!\n"),0;
  write(
"This gate is locked with too strong magic for anyone to open "
"except a wizard.\n");
  return 1;
}

int do_west() {
  if (!this_player()) return 0;
  write("The gate is securely locked, you cannot walk through it.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("Closed Gate");
  SetIntLong(
"You are standing at the edge of the forest.  The path splits in "
"three ways.  There is a closed gate straight ahead which blocks "
"you from going west.\n");
  AddDetail(({"gate","closed gate"}),
"It's securely closed and you feel strong magic barring it.\n");
  SetIndoors(0);
  AddDetail(({"forest","edge","edge of the forest"}),
"The forest stretches to the south and east.\n");
  AddDetail("path","It splits in three ways.\n");
  AddRoomCmd("unlock",#'do_unlock);
  AddRoomCmd("open",#'do_open);
  AddRoomCmd("west",#'do_west);
  AddExit("east","./pa4n4");
  AddExit("south","./pa5n5");
  AddExit("north","./pa5n3");
}
