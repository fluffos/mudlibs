inherit "std/room";
#include "path.h"
#include <rooms.h>

create() {
	::create();
	SetIntShort("Nightfall Central Airport, Terminal 1");
	SetIntLong(
"You are standing at Terminal 1 of the Nightfall Central Airport. This is "
"where the flying dragons of the Nightfall Flightdragons Airways land. "
"You can see more terminals to the west and the exits to east and north. "
"Usually there's a huge sign standing here.\n");
        SetIndoors(0);
        AddExit("east", "./narr_alley");
        AddExit("north", "./vill_track");
        AddExit("west", "./airport2");
        AddItem(RANDY("/obj/airsign"),REFRESH_REMOVE);
        AddItem(RANDY("dragon/map"),REFRESH_REMOVE);
}

look_arrive() {
	return "A huge city comes into sight. You land on a large airport.\n";
}

look_depart() {
	return "You throw a last view on Nightfall City. It looks great from above!\n";
}

