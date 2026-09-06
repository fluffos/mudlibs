#include "path.h"
inherit "std/room";

void create() {
	::create();
	SetIntShort("Filthy Street");
	SetIntLong(
"You are on a filthy street in the southwestern corner of Nightfall City. "
"There are some ruins of former shops here. There are also many trees around. "
"Looking further south, you can see the forest. To the west are the gates "
"of the city's lowlevel training park.\n"
"You can go north to the city or south to the forest.\n");
        AddExit("south", "./forest2");
        AddExit("north", "./row1");
        AddExit(({"enter","west"}), PARK("paentr"));
	HideExit("enter",1);
  SetIndoors(0);
}
