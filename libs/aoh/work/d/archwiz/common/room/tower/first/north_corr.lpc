inherit "/std/room";

#include "path.h"

void create() {
	::create();
	SetIntShort("North corridor of the first floor");
	SetIntLong(
"You are in the long north corridor of the first floor. To the west is the "
"Quest-Office. The Department of Defence lies to the north.\n");
        AddExit("west",COMMON("quests/office"));
        AddExit("north",COMMON("defence/office"));
	AddExit("south",TOWER("center"));
}

