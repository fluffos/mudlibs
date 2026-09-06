inherit "std/room";

#include <rooms.h>
#include <moving.h>
#include <properties.h>

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong(
"This is a twisty maze of little passages, all alike. "
"A skeleton, probably the remains of a luckless adventurer, lies here.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"twisty maze","maze","little maze","passages","passage",
	      "little passages","little passage"}),#'IntLong);
  AddDetail(({"skeleton","remains"}),"Looks really dead.\n");
  AddExit("north","./maze4");
  AddExit("west","./maze5");
  AddExit("east","./deadend2");
  AddItem("/obj/key",REFRESH_REMOVE,
    ([P_SHORT: "skeleton key",
      P_LONG:  "It is a long, rusty old key.\n",
      P_ADS: ({"a","long","rusty","old","skeleton"}),
      P_KEYIDS: ({"skeleton_grating"}),
      P_WEIGHT: 20,
      P_VALUE:  5]) );
}
