inherit "/std/room";

#include <rooms.h>
#include "path.h"

int do_sit(string str) {
  if (!this_player()) return 0;
  if (!str) return 0;
  if ((str!="on chair") && (str!="on the chair") &&
      (str!="chair")) return 0;
  this_player()->command_me("sit at the table");
  return 1;
}

void create() {
	::create();
	SetIntShort("The Voting Room at the Central Tower of Nightfall");
	SetIntLong(
"You are in a small room near the entrance of the Tower. A large table "
"occupies most of the room. There are some forms lying on the table, "
"and in the middle is a slot wide enough to feed it with the forms. "
"A chair invites you to sit down, read the forms and vote. The exit "
"is to the north.\n");
	AddExit("north","./adv_hall");
	AddDetail("table", 
"It is a large mahagoni table with a slot in the middle. You can sit down "
"before it to vote.\n");
	AddDetail("forms",
"There are several forms on subjects to vote on. Sit down to read them.\n");
	AddDetail("chair",
"You feel that it won't be a good idea to sit on this chair. Perhaps you "
"should try to 'sit at the table'?\n");
	AddRoomCmd("sit",#'do_sit);
	AddItem(OBJ("voting_table"),REFRESH_HOME);
}
