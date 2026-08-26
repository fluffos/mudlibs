

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "Mr. Ades' Classroom.");
  
set("long", @ENDLONG
Mrs. Krauss' classroom is imaculate.  The walls are green, with no decorations
whatsoever.  At the front of the room is a chalkboard.  The desks are plain
wood with not even a pencil mark on them.
ENDLONG
);

  set("item_desc", ([
    
    "chalkboard" : "On the left side of the board there are mathimatical
calculations, on the right side, the words 'I will not speak out of turn' are
written 99 times.\n",
    "desks" : "You guess someone makes the children keep their desks very neat.\n",
     "walls" : "These walls remind you of a prison.\n",
    

]) );
   set("objects", ([
    MON(mrskrauss) : 1,
    MON(kchild1) : 1,
    MON(kchild2) : 1,
    MON(kchild3) : 1,
    
    
  
]) );
  
  set("exits", ([
    "south" : ROOMS(school),
   
 

 ]) );
  ::create();  
}
