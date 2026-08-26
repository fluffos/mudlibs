

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "At an Intersection .");
  
set("long", @ENDLONG
The road comes to an intersection here.  Small wooden buildings begin to 
crop up to your north and east.  The buildings appear to be made of brick 
and wood.  You can see the holy symbol of Dryox on a building to the east.
There is an intersection to the north.
ENDLONG
);

  set("item_desc", ([
    "trees" : "These are oak trees grown to full maturity.\n",
    "buildings" : "The buildings appear to be well made by either dwarven
or human hands.\n",
    "symbol" : "You will have to get closer to examine that.\n",
    "intersection" : "The road turns to the east and west as the road 
progresses north.\n",
    "road" : "This road is well trodden, suggesting regular use.\n",
    "brick" : "The bricks are made of a hardened, red mud.\n",
    "wood" : "It's mostly cedar and pine wood.\n",
   ]) );
   
  set("smell", ([
    "default" : "You can make out the sent of incense burning, apparrently from
the east.\n", ]) );

  
  set("exits", ([
    
    
    "south" :  ROOMS(main.c),
    "north" : ROOMS(inter2.c),
    "east" : ROOMS(church.c),
    
  ]) );
  ::create();  
}
