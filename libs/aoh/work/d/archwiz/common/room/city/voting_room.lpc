#include "path.h"
#include <rooms.h>

inherit "/std/room";

query_prevent_shadow() {return 1;}

void create() {
	::create();
	SetIntShort("The Voting Room at the Adventurers Guild");
	SetIntLong(
"You are in a small room near the entrance of the Guild. A large table "
"occupies most of the room. There are some forms lying on the table, "
"and in the middle is a slot wide enough to feed it with the forms. "
"A chair invites you to sit down, read the forms and vote. The exit "
"is to the west.\n");
	AddExit("west",	"/p/guilds/adventurers/room/nf-city");
	AddDetail("table", 
"It is a large mahagoni table with a slot in the middle. You can sit down "
"before it to vote.\n");
	AddDetail("forms",
"There are several forms on subjects to vote on. Sit down to read them.\n");
	AddItem(OBJ("voting_table"),REFRESH_HOME);
}
