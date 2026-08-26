
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 0);


  set("short", "The beginning of a narrow tunnel.");
  
set("long", @ENDLONG
This is the entrance to the lower portion of the cave.  The walls are 
colored slate grey, the color of natural granite and are completely smooth
and barren.
ENDLONG
   );

  


  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    
    "air"  : "It reminds you of something you can't quite place, a sweet, decaying odor.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear a light clicking sounds.\n",
    
    
    
  ]) );
  set("objects", ([
    "ant" : MON(drone)
  ]) );

  set("exits", ([
    
    "east" : ROOMS(l2),
    "up" :  ROOMS(cave3),
    
    
  ]) );
  ::create();  
}
