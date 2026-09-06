inherit "/std/room";

#include "path.h"

void create() {
	::create();
	SetIntShort("South corridor of the first floor");
	SetIntLong(
"You are in the long south corridor of the first floor. To the west is the "
"Office of Health. The Office of Guilds is to the east. South is a magic "
"field that leads into the police station.\n");
	AddExit("west",COMMON("health/office"));
	AddExit("north",TOWER("center"));
	AddExit("east",COMMON("guilds/office"));
        AddExit("south",CITY("policehq"));
}
