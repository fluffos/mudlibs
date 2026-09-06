/* made by RoomMaker V0.991 (c) Sique 2/1993 */

#include "path.h"
#include <doors.h>
inherit "/std/room";

try_north()
{
  write("You bump into the closed door of the Hardrock Cafe. "
"Better wait until it reopens.\n");
  return 1;
}

create()
{
  ::create();
  SetIntShort("Skid Row");
  SetIntLong(
"You are trudging along Skid Row, kicking empty Popov "
"bottles out of your way as you go. "
"To the north you see the famous Hard Rock Cafe. "
"In former times it was a great adventure club, but its  "
"new owner had it driven down. "
"To the south you see the Metallica Recycling Center. "
"Here you can sell all your stuff you don't need anymore.\n"
    );
  AddExit("west","./row3");
  AddExit("east","./row5");
  AddDoor("south","./metallica","exit",
"This door leads into the Metallica Recycling Center.\n",
0,DOOR_STATUS_OPEN);
  SetIndoors(0);
  AddExit("north",#'try_north);
  HideExit("north",1);
}
