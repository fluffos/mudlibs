#include "path.h"

inherit "/std/room";

void create() {
	::create();
	SetIntShort("South corridor of the second floor");
	SetIntLong(
"You are in the south corridor on the second floor. It's the level where "
"the Domain Offices are located.  West of you is the Hell domain office. "
"To the east you can find the office of Woodland and to the south "
"you can go further along the floor.\n");
	AddExit("north","./center");
	AddExit("south","./south2");
   AddExit("west","./o_hell");
   AddExit("east","./o_woodland");
}
