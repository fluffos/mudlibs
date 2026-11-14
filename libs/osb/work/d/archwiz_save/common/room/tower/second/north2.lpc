inherit "/std/room";

#include "path.h"

void create() {
	::create();
	SetIntShort("North corridor of the second floor");
	SetIntLong(
"You are in the north corridor on the second floor. It's the level where "
"the Domain Offices are located. East is the office of the Daydream Domain, "
"west the office of the Volcano-Isle Domain. To the north is the office of the "
"Valhalla Domain.\n");
	AddExit("east","./o_daydream");
        AddExit("west","./o_volcano");
	AddExit("south","./north1");
        AddExit("north","./o_valhalla");
}
