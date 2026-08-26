#include "../defs.h"

inherit ROOM;   
int ring;
void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The beginning of a cobblestone street.");
  
set("long", @ENDLONG
The main road has turned east into a cobblestone street.  Houses line the north 
and south sides of the road.  The town looks larger than you might have 
expected, there seems to be a lot of traffic coming from the east and two
homes lie to the north and south, close enough to give access to the main street. 
ENDLONG
);

  set("item_desc", ([
      "road" : "The road is well worn.\n",
      "town" : "It appears that this town is completely populated by dwarves.\n",
      "traffic" : "There are many different kinds of commerce happening here.\n",
       "homes" : "It looks like there may be someone home.\n",
      "houses" : "They look small but quaint.\n",
]));
  set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", 
    
  ]) );
  set("exits", ([
    "north" :  ROOMS(house),
     "south" : ROOMS(house2),
     "east" : ROOMS(street2),
     "west" : ROOMS(corner), 
     ]) );
  ::create();  
}


