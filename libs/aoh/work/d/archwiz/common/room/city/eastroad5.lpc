/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"
// removed, because /d/avalon does not exist
// Sonic, 20-May-1997
//inherit  HOUSEROAD;
inherit "/std/room";

create()
{
  ::create();
  SetIntShort("East road");
  SetIntLong(
"You are walking on east road. To the north and south, "
"east road continues and leads "
"to Nightfall City, the capital of this world. You can see the northern part "
"of the city to the south. To the west lies the famous Eastroad Inn.\n"
    );

// I removed the exit to orient too... Sonic, 20-May-1997
//  AddExit("north","/d/orient/common/room/eastroad/s33");
  AddExit("south","./eastroad4");
  AddExit("west","./inn");
  SetIndoors(0);
}
