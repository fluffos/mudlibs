#include "../defs.h"

inherit ROOM; 
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "On a narrow staircase.");
  
set("long", @ENDLONG
This is the second floor of the Town Hall.  The walls are made of dry 
cedarwood and oak.  To the north you can smell a sweet burning smoke 
down a long hallway, coming from a large office.  You can see two small
offices to the west and south
of here.
ENDLONG
);

  set("item_desc", ([ 
      "smoke" : "It's a thick, grey smoke.\n",
      "walls" : "These walls look well-made, but a fire trap waiting to happen\n",
      "hallway" : "Try \"look\", you are standing in it.\n",
      "office" : "A sign on the door proclaims it to be the mayor's office.\n",
      "offices" : "These are the offices of the secretary and treasurer of the town of
Rithik.\n",

]) );  
set("smell", ([
    "default" : "The smoke smells like a very rare tobacco.\n", 
  ]) );
  set("exits", ([
     "down" :  ROOMS(stairs),
     "west" : ROOMS(o_1),
     "north" : ROOMS(mayo),
     "south" : ROOMS(o_2),
     ]) );
  ::create();  
}