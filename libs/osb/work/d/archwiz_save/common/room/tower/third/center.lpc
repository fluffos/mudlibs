#include "path.h"

inherit "/std/room";

void create() {
	::create();
	SetIntShort("The center of the third level in the Tower of Administration");
	SetIntLong(
"You are at the center of the third level in the Tower of Administration. "
"To the north is the great meeting hall of the wizards and to the south "
"the voting room. To the west is the small conference room for Archwizard "
"meetings. Only archwizards are allowed there. Marble stairs lead down to "
"the second level.\n");
	AddExit("north","./conferences");
	AddExit("down",TOWER("second/center"));
}
