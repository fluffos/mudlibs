#include "path.h"
inherit "std/room";

create() {
  ::create();
	SetIntShort("The border of the forest");
	SetIntLong(
"You are at the border of the deep forest. The trees are too dense to the  "
"south but a path leads east, along the border. You can also go back north, "
"where you notice some rotten buildings, which obviously once belonged to "
"Nightfall City but now are left by their inhabitants.\n");
        AddExit("north", "./forest1");
        AddExit("east",  "./forest3");
  SetIndoors(0);
}
