/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Skid Row");
  SetIntLong(
"You have reached the eastern end of Skid Row. "
"To the north you see the crop fields of Nightfall. "
"The Blue Highway leads off to the south.\n"
    );
  AddExit("north","./field");
  AddExit("south","./blue_highway");
  AddExit("west","./row6");
  SetIndoors(0);
}
