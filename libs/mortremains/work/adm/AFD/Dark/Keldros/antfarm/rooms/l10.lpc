
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 0);


  set("short", "In a narrow tunnel.");
  
set("long", @ENDLONG
The cave widens here and light can be seen ahead.  The walls remain barren,
but you notice heat is radiating from the room to the east.
ENDLONG
   );

  


  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    
    "air"  : "It reminds you of something you can't quite place, a sweet, decaying odor.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear a light clicking sounds.\n",
    
    
    
  ]) );

  

  set("exits", ([
    
    "east" : ROOMS(end),
    "west" :  ROOMS(l9),
    
    
  ]) );
set("objects", ([
    MON(warant) : 2,
  ]) );
   set("pre_exit_func", ([
     "east" : "guarded",
  ]) );
  ::create();
}

int guarded() {


  if (present("ant", TO)) {
   write("The warrior ant refuses to let you pass.\n");
   return 1;
  }
  return 0;
}
