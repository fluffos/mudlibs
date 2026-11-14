
#include "path.h"
inherit "std/room";

create(arg) {
 ::create(arg);
 SetIntShort("South of white house");
 SetIntLong(
"You are facing the south side of a white house. "
"There is no door here and all the windows are barred. "
"To the east you see a monastery. It looks old, but it seems to be "
"inhabited by monks. Maybe you can go into the monastery? To the west lies "
"the entrance to the Nightfall City Opera House.\n");
 SetIndoors(0);
 AddDetail(({"opera","opera house"}),
 "The ornate opera house is very old, but in excellent condition.\n");
 AddDetail(({"windows","window"}),
 "They are all barred. You can't break them open.\n");
 AddDetail("monastery",
 "It is an old monastery with very massively built walls and little windows.\n");
 AddExit("northwest","./whouse");
 AddExit("south","./vill_track");
 AddExit("west",OPERA("entrance"));
 AddExit("east","./monastry");
}

