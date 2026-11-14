/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Road leading east and west");
  SetIntLong(
"You are on a road going out of Nightfall City, the capital of this world. "
"To the east the road widens out as it leads down to the shore. You can see "
"a small harbour in the distance and the sea behind it. To the west lies  "
"the city. To the north an estate agency has opened. Farther to the north "
"a railroad track is visible, running upwards from the ground to a metal "
"structure east.\n"
    );
  AddExit("west","./vill_shore");
  AddExit("east","./vill_shore2");
  AddExit("north","./agency");
  SetIndoors(0);
}
