/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"
// removed, because /d/avalon does not exist
// Sonic, 20-May-1997
//inherit HOUSEROAD;
inherit "/std/room";

try_down() {
  write("You walk on top of the escalator. After a few minutes you notice it doesn't "
        "move. You give up and decide next time to read the sign.\n");
  return 1;
}

read(string str) {
  if (!str) return 0;
  if (lower_case(str || "") == "sign")
  { write("You read: Escalator out of order!\n\
           C.A.R.T.-Station closed!\n");
  return 1; }
  return notify_fail("What do you wanna do?\n");
}

create()
{
  ::create();
  SetIntShort("East road");
  SetIntLong(
"East road runs north-south. Sun alley is to the west. An old escalator leads "
"down. There is a sign standing next to it.\n"
    );
  AddDetail("sign",
"You read: Escalator out of order!\n\
          C.A.R.T.-Station closed!\n"
    );
  AddDetail("escalator","This escalator is obviously out of order!\n");
  AddExit("north","./eastroad4");
  AddExit("south","./eastroad2");
  AddExit("west","./sunalley1");
  AddExit("down",#'try_down);
  HideExit("down",1);
  SetIndoors(0);
  AddRoomCmd("read",#'read);
}
