inherit "std/room";

#include "path.h"

void create() {
	::create();
	SetIntShort("East corridor of the second floor");
	SetIntLong(
"You are in the east corridor on the second floor. It's the level where "
"the Domain Offices are located. North is the office of Vecna's Realm. "
"To the south lies the office of the Domain Shadows.\n");
	AddExit("west","./east1");
	AddExit("south","./o_shadows");
	AddExit("north","./o_vecna");
}
