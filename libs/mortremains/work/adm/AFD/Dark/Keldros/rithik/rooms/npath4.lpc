

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "A Juncture of Paths.");
  
set("long", @ENDLONG
The north path of Rithik is very rocky and difficult to traverse, suggesting
little use.  The cedarwood trees are twisted and dark, their unseen eyes
glare at you from their hidden position.  You can see a weed ridden trail
to the west through the trees, it appears quite dark.  The path continues
to the north and south.
ENDLONG
);

  set("item_desc", ([
    "trees" : "The cedar trees have a dark bark and are twisted, with an
evil look about them.\n",
    "path" : "This is a rocky path, it doesn't appear this path is used often.\n",
   ]) );
   
  set("smell", ([
    "default" : "You smell cedar.  A slight breeze carries a smoky smell
from the south.\n", 
    "trees" : "These trees emit a dank and pungent odor.\n",
]) );
  
  set("exits", ([
    "south" :  ROOMS(npath3),
    "north" : ROOMS(npath5),  
    "west" : ROOMS(trail),  
]) );
  ::create();  
}
