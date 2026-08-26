

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "A Juncture of Paths.");
  
set("long", @ENDLONG
The weeds begin to thin out a bit.  The brush is difficult to see over
but you can see smoke from a campfire to the west.  The sky remains
a deep, almost blood red.
ENDLONG
);

  set("item_desc", ([
    "weeds" : "There are many different different varieties.\n",
    "brush" : "There are many different different varieties.\n",
     "path" : "This is a rocky path, it doesn't appear this path is used often.\n",
   ]) );
   
  set("smell", ([
    "default" : "You smell cedar.  A slight breeze carries a smoky smell
from the south.\n", 
    "trees" : "These trees emit a dank and pungent odor.\n",
    "sky" : "It is glowing a deep blood-red.\n",
]) );
  
  set("exits", ([
    
    "east" : "/d/Dark/Keldros/rithik/rooms/trail",  
    "west" : ROOMS(camp),  
]) );
  ::create();  
}
