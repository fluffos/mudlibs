#include "path.h"
#include <rooms.h>
inherit "std/room";

create() {
	::create();
	SetIntShort("Nightfall Central Airport, Terminal 2");
	SetIntLong(
"You are standing at Terminal 2 of the Nightfall Central Airport. This is "
"where the flying dragons of the Nightfall Flightdragons Airways land. "
"You can see more terminals to the east. You have a great view from here. "
"Usually there's a huge sign standing here.\n");
        SetIndoors(0);
        AddExit("east", "./airport1");
        AddItem(RANDY("obj/airsign"),REFRESH_DESTRUCT);
        AddItem(RANDY("dragon/map"),REFRESH_REMOVE);
}

look_arrive() {
	return "A huge city comes into sight. You land on a large airport.\n";
}

look_depart() {
	return "You throw a last view on Nightfall City. It looks great from above!\n";
}

