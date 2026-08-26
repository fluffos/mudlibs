#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "A Room Full of Slaves.");
  
set("long", @ENDLONG
 The heat in this room blasts through your soul.  The walls are 
completely devoid  of detail, barren and slate grey.  You notice brown 
stains on the ground, that appear not to be naturally formed. A pile of chains in the northeast corner of the room.
ENDLONG
   );

  set("item_desc", ([
  "walls" : "These walls have been mined bare and cut smooth.\n",
    "wall" : "These walls have been mined bare and cut smooth.\n",
    "chains" : "These chains are made of iron and have metal shackles on both ends.\n",
    "stains" : "The stain looks to have been formed by a liquid of some sort.\n",
    

    
                     ]) );
   set("search_desc", ([
     "wall" : "This wall is completely smooth.\n",
     "chains" : "You find traces of what you believe to be blood",

   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    "wall"  : "You smell the nothing except for rock.\n",
    
    
  ]) );
  set("listen", ([ "default" : "You hear a light clicking sounds.\n", ]) );
  set("objects", ([
    MON(slave) : 3,
    MON(slavedriver) : 1,
  ]) );

  set("exits", ([
    "west" : ROOMS(further.c),
    
  ]) );
  ::create();
  
}
