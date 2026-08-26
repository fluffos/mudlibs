

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside("zone","2");
  set("author", "Waxer");  

  set("light", 1);


  set("short", "On a trail ridden with weeds.");
  
set("long", @ENDLONG
The weeds surrounding you are very sharp, delivering
minor nicks and scratches.  The ground beneath you is
soft and moist.  This trail leads to the west and east.
ENDLONG
);

  set("item_desc", ([
    "nicks" : "Though painful, they don't appear to have done any significant damage.\n",
    "scratches" : "Though painful, they don't appear to have done any significant
damage.\n",
    "ground" : "It has rained recently, giving the ground a soft, moist feel.\n",
    "weeds" : "There are many different different varieties.\n",
    "path" : "This is a rocky path, it doesn't appear this path is used often.\n",
   ]) );
   
  set("smell", ([
    "default" : "There is a bitter scent to the air, apparently coming from
the weeds.\n", 
    "weeds" : "The weeds make your eyes water with their bitter scent when
you smell them.\n",
]) );
  
  set("exits", ([
    "east" : ROOMS(npath4),
    "west" : "/d/Dark/Circus/rooms/trail2",  
]) );
  ::create();  
}
