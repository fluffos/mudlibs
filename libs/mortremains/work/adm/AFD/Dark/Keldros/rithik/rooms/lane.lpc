#include "../defs.h"

inherit ROOM;   

void create() {
seteuid(getuid()); 

set_outside("zone","2");

set("author", "Waxer");  

set("light", 1);

set("short", "On Victory Lane.");
  
set("long", @ENDLONG
Victory lane is a dirt path with traces of cobblestones that litter your way.
The sounds of activity are dim here, but you can still make them out.To the south
you see the end of victory lane in a circle with a pole in the center.  North on
Victory lane you see the cobblestone stones become thicker as the lane continues
in that direction.
ENDLONG
);

set("item_desc", ([
 "lane" : "The lane leads to the north and south.\n",
 "cobblestone" : "Thick, rounded stones cover \"Victory Lane\".\n",
 "circle" : "The lane comes to an end to the south, you see a pole in the ending court.\n",
]));
set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", 
  ]) );
  
set("exits", ([ 
     "north" : ROOMS(lane2),
     "south" : ROOMS(circle),
     "west" : ROOMS(inter3),
     "east" : ROOMS(jhouse),
     ]) );
  
::create();  

}


