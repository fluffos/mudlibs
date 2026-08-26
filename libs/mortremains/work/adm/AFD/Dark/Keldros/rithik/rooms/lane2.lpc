#include "../defs.h"

inherit ROOM;   
int ring;
void create() {
seteuid(getuid()); 

set_outside();

set("author", "Waxer");  

set("light", 1);

set("short", "The corner of the street and Victory Lane.");
  
set("long", @ENDLONG
The cobblestones become more frequent on the ground below you.  Northward on
the path you see it ends at a very large white mansion, but large gates prevent 
you from going in that direction.  To the east you see a two story wood building
that looks quite official. Westward on the leads down a cobblestone street.
ENDLONG
);
set("item_desc", ([
    "ground" : "It's dirt brown, with cobblestones covering it.\n",
    "mansion" : "A very wealthy family must live in that house.\n",
    "building" : "You believe this may be a governmental building.\n",
    "cobblestones" : "Thick, rounded stones cover the path to the west and south.\n",
    "street" : "This street is bustling with activity.\n",
]) );
set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", 
  ]) );
  
set("exits", ([ 
    
     "south" : ROOMS(lane),
     "west" : ROOMS(street3), 
     "east" : ROOMS(thall),
 ]) );
  
::create();  

}


