#include "../defs.h"
object dw;
inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside("zone", "2");
  set("author", "Waxer");  

  set("light", 1);


  set("short", "An intersection.");
  
set("long", @ENDLONG
This is an intersection of paths.  To the north you can see a cobblestone street.
To the south you can smell incense burning, it appears to be a church 
celebrating something.  To the east you see a sign that marks a lane
"Victory Lane".
ENDLONG
);

  set("item_desc", ([ 
 "sign" : "It is written in both dwarven and common.\n",
 "street" : "You are too far away to examine that.\n",
 "path" : "You sense this path may lead somewhere interesting.\n",
 "building" : "You see many dwarves going in an out of the building carrying bags.\n",
 "lane" : "The lane leads to the east.\n",
 "church" : "By the steeple on the top of it, it looks like an old fashioned church.\n",

 ]) );
set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", 
    
  ]) );
  set("exits", ([
    "north" :  ROOMS(street3.c),
     "south" : ROOMS(church.c),
     "east" : ROOMS(lane),
     ]) );
  ::create();  
}
void reset()
{
  if(!dw){
     dw=clone_object(MON(ldwarf));
     dw->move(TO);
   }
::reset();
}

