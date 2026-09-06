inherit "/std/room";
#include "path.h"

void create() {
	
	::create();
    
	SetIntShort("The center of the third level in the Tower of Administration");
	SetIntLong(
"You are at the center of the third level in the Tower of Administration. "
"To the north is the great meeting hall of the wizards and to the south "
"the voting room. Marble stairs lead down to the second level.\n"
"To the west and east are small corridors.\n");
	AddExit("north",   	"./conferences");
	AddExit("south",   	"./voting");
	AddExit("down",   	TOWER("second/center"));
}



