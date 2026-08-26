  
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "A small rest area.");
  
set("long", @ENDLONG
The walls in this portion of the cave are marked with brown and 
black stains.  Yellow powder coats the floor.  The ceiling here is low 
and the air stale.  This part of the cave could serve as a suitable 
rest area.  
ENDLONG
   );

  set("item_desc", ([
  "walls" : "The walls appear to have been crafted with rough instruments, as a result of what appears to be mining.\n",
    

    
     "dust" : "This dust is a yellow powder that has traces of larger brown and black powder.\n",
     "ground" : "The ground is covered with fine, yellow dust.\n" 
   ]) );
   set("search_desc", ([
     "wall" : "This wall is completely bare.\n",

   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    
    "air"  : "It reminds you of something you can't quite place, a sweet, decaying odor.\n",
    "ground" : "It has a sweet scent, it appears to be a sugary substance.\n",
    "dust" : "It has a sweet scent, it appears to be a sugary substance.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear a light clicking sounds.\n",
    "wall" : "You hear sounds deep within the wall, you think.\n"
    
    
  ]) );
  set("objects", ([
    MON(woken) : 3
  ]) );

  set("exits", ([
   
    "southeast" : ROOMS(cave1),
    "east" : ROOMS(cave6),
  ]) );
  ::create();
  
}
