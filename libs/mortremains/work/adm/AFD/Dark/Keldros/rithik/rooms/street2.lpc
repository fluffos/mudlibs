#include "../defs.h"

inherit ROOM; 
void create() {
  seteuid(getuid());   
 set_outside("zone","2");
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The beginning of a cobblestone street.");
  
set("long", @ENDLONG
The cobblestone street continues.  To the west the smell of burkhberry pie is
pronounced.  To the east the traffic becomes more frequent.  To the north
you can see a narrow path that leads through the forest.  To the south is a
small building with a sign over the door. 
ENDLONG
);

  set("item_desc", ([ 
      "sign" : "You are too far away to look at the sign.\n",
      "traffic" : "There are many different kinds of commerce happening here.\n",
       "path" : "You sense this path may lead somewhere interesting.\n",
       "building" : "You see many dwarves going in an out of the building carrying bags.\n", 
 ]) );
set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", 
    
  ]) );
  set("exits", ([
    "path" :  ROOMS(npath),
     "south" : ROOMS(shop),
     "east" : ROOMS(street3),
     "west" : ROOMS(street), 
     ]) );
  ::create();  
}


