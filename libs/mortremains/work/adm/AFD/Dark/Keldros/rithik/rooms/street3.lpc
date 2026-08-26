#include "../defs.h"

inherit ROOM; 
void create() {
seteuid(getuid()); 

set_outside("zone","2");
set("author", "Waxer");  
set("light", 1);
set("short", "On a cobblestone street.");

set("long", @ENDLONG
The cobblestone street continues.  Birds chirping and the vibrant 
smells of Rithik excite your senses.  Westward on the path you see 
activity around  a small building to the south.   The street intersects 
with a dirt path to the east and the south.
ENDLONG
);

set("item_desc", ([
   "street" : "It's a well-worn cobblestone street.\n",
   "birds" : "They are mostly harpin and doublestay birds.\n",
    "building" : "The building must be doing quite a bit of business.\n",
   "path" : "It's a simple dirt path.\n",
]));

set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", 
  ]) );
  
set("exits", ([ 
     "west" : ROOMS(street2.c),
     "south" : ROOMS(inter3.c),
     "east" : ROOMS(lane2), 
     ]) );
  
::create();  

}


