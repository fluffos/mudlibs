#include "path.h"

inherit "/std/room";

void create() {
	::create();
	SetIntShort("West corridor of the second floor");
	SetIntLong(
"You are in the west corridor on the second floor. It's the level where "
"the Domain Offices are located. To the north is the office of the "
"Halfling Domain. South you can enter the Office of the Archwiz Domain.\n");
	AddExit("west","./west2");
	AddExit("north","./o_halfling");
	AddExit("east","./center");
	AddExit("south","./o_archwiz");
}
