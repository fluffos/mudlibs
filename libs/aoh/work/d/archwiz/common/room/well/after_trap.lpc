/*
* This is a part of NF-City. 30.01.1994 Joern
* Last Changes by Thragor, 04mar94
* Changes by Cadra, 30sep94
*/

#include <moving.h>
#include "path.h"
#include <rooms.h>
inherit "/std/room";

east()
{
 if (!WELL("door_trap")->query_west_door())
 {
  write("The door is closed.\n");
  return 1;
 }
 this_player()->move(WELL("door_trap"),M_GO,"east");
 return 1;
}

look_door() {
 if (!WELL("door_trap")->query_west_door()) {
   return "The door is cloased.\n"; }
 return "The door is open.\n";
}

create()
{
 ::create();
 SetIntShort("Black room");
 SetIntLong("This is the black room. There is a door to the east.\n");
 SetIndoors(1);
 SetBright(0);
 AddDetail(({"room","black room"}),QueryIntLong());
 AddDetail(({"walls","wall","floor","ground","ceiling",
 "black walls","black wall","black floor",
 "black ground","black ceiling"}),
"Everything is black here.\n");
 AddDetail(({"door","east door","door to the east"}),
#'look_door);
 AddRoomCmd("east",#'east);
 AddItem(MONSTER("black_rat"),REFRESH_HOME);
}
