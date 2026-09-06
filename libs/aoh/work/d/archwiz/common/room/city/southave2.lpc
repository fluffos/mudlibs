/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"
inherit "/std/room";

create()
{
  ::create();
  SetIntShort("South Avenue");
  SetIntLong(
"You are on South Avenue, a quiet suburban lane running east-west. "
"South Avenue crosses a big stream at this point. You can walk over the "
"bridge made of white stones to the west where you can see a forest. "
"To the south you see good ole Raistlin's McDonalds. "
"To the north you can see a small house.\n");
  AddDetail("house",
"A small house. The walls are painted in strange colours.\n"
    );
// Commented out the exit, as it doesn't exist here.
// Sonic, 18-May-1997
//  AddExit("north",DREAM("dreamhouse"));
  AddExit("south","+archwiz/raistlin/rooms/entrance");
  AddExit("west","./southave1");
  AddExit("east","./boul3");
  SetIndoors(0);
}
