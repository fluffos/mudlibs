

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The Old Path continues.");
  
set("long", @ENDLONG
The north path of Rithik is very rocky and difficult to traverse, suggesting
little use.  The cedarwood trees are twisted and dark, their unseen eyes
glare at you from their hidden position.  To the north and south the path 
continues.
ENDLONG
);

  set("item_desc", ([
    "eyes" : "The holes animals have created in the trees give the trees the appearance
that they are looking at you.\n",
    "trees" : "The cedar trees have a dark bark and are twisted, with an
evil look about them.\n",
    "path" : "This is a rocky path, it doesn't appear this path is used often.\n",
    "town" : "The buildings are small in stature but look quite quaint.\n",
   ]) );
   
  set("smell", ([
    "default" : "You smell cedar.  A slight breeze carries a smoky smell
from the south.\n", 
    "trees" : "These trees emit a dank and pungent odor.\n",
]) );
  
  set("exits", ([
    "south" :  ROOMS(npath),
    "north" : ROOMS(npath3),  
  ]) );
  ::create();  
}
