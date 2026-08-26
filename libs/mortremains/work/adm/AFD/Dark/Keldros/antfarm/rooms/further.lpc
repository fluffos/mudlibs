  
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "Inside the cave.");
  
set("long", @ENDLONG
This is a rock cave, the walls are colored slate grey and have large concaves
in them that appear to be the result of someone digging at them with a 
mining instrument of some sort.  The ground beneathe you is a soft
yellow powder that billows up dust with every step you take.  
ENDLONG
   );

  set("item_desc", ([
  "walls" : "The walls appear to have been crafted with rough instruments, as a result of what appears to be mining.\n",
    "cave" : "This cave appears to have been built by humanoid creatures.\n",
    "concaves" : "The concaves run nearly horizontal along the walls, quite 
deliberately made.  You believe something has been trying to extract something from the walls.\n",
     "dust" : "This dust is a yellow poweder that has traces of larger brown and black powder.\n",
     "ground" : "The ground is covered with fine, yellow dust.\n" 
   ]) );
   set("search_desc", ([
     "wall" : "You find feint traces of what appears to be copper ore.\n",

   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    "wall"  : "Your body convulses with an enormous sneeze as you inhale the dust off the wall.\n",
    "air"  : "It reminds you of something you can't quite place, a sweet, decaying odor.\n",
    "ground" : "It has a sweet scent, it appears to be a sugary substance.\n",
    "dust" : "It has a sweet scent, it appears to be a sugary substance.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear a light clicking sounds.\n",
    "wall" : "You hear sounds deep within the wall, you think.\n"
    
    
  ]) );
  set("objects", ([
    MON(minant) : 2,
    MON(workant) : 1,
  ]) );

  set("exits", ([
    "west" : ROOMS(cave3),
    "south" : ROOMS(entrance),
    "east" : ROOMS(cave2),
    "north" : ROOMS(cave1),
  ]) );
  ::create();
  
}
