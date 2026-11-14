/*
* Tunnels. 30.01.1994 Joern
* Last Changes by Thragor, 04mar94
* Changes by Cadra, 30sep94
*/

#include "path.h"
#include <rooms.h>
#include <moving.h>

#define DOORTRAPROOM WELL("door_trap")

inherit "/std/room";


int west()
{
 if (DOORTRAPROOM->query_west_door())
 {
  write("The door is closed!\n");
  return 1; 
 }
 if (!this_player()) return 0;
 this_player()->move(DOORTRAPROOM,M_GO,"west");
 return 1;
}

look_west() {
  if (DOORTRAPROOM->query_west_door())
    return "The door is closed. There is something strange at one of the walls.\n";
  return "The door is open. There is something strange at one of the walls.\n";
}

int pull(string str)
{
 notify_fail("Pull what?\n");
 if (str!="lever") return 0;
 DOORTRAPROOM->toggle_door();
 return 1;
}

int open(string str)
{
 notify_fail("Open what?\n");
 if (str!="door") return 0;
 write("Yes, yes, but how?\n");
 return 1;
}

create()
{
 ::create();
 SetIntShort("Down the well");
 SetIntLong(
"You are at the ground of an old well. A ladder is leading up. To the west a "
"door can be seen.\n");
 SetIndoors(1);
 SetBright(0);
 SetIntNoise("You hear the shrill sounds of rats.\n");
 SetIntSmell("It smells of decay.\n");
 AddDetail(({"door","west door"}),#'look_west);
 AddDetail(({"strange","something","something strange"}),
"There is a level near the door.\n");
 AddDetail(({"walls","wall"}),
"There is a lever next to the west door.\n");
 AddDetail(({"ground","floor","ground of an old well"}),
QueryIntLong());
 AddDetail("ladder","It leads up.\n");
 AddDetail("ceiling",
"There is no ceiling, you can leave the well up.\n");
 AddDetail("lever","It can still be pulled.\n");
 AddExit("up",CITY("narr_alley"));
 AddExit("west",#'west);
 AddExit("north","./maze1");
 AddRoomCmd("pull",#'pull);
 AddRoomCmd("open",#'open);
}
