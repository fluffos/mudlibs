#include "path.h"

inherit "/std/room";

void create() {
	::create();
	SetIntShort("South corridor of the second floor");
	SetIntLong(
"You are in the south corridor on the second floor. It's the level where "
"the Domain Offices are located.  West of you is the Exu domain office. "
"To the east you can find the office of Ireland and to the south "
"you can enter the office of Myth Drannor.\n");
	AddExit("north","./south1");
   AddExit("west","./o_exu");
   AddExit("east","./o_ireland");
   AddExit("south","./o_drannor");
}
