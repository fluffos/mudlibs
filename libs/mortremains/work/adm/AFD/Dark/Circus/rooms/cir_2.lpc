#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "Near the Big Top.");
  
set("long", @ENDLONG
The Big Top tent looms over you to the west.  Hay litters the ground at
your feet and you can smell stale popcorn and wet fur.
ENDLONG
);

  set("item_desc", ([
    "tent" : "The tent is perhaps three hundred feet in diameter.  The tent is
colored white, with gigantic red stripes that run verticle along all sides
of it.  You would assume it is a circus tent.\n",
    "flag" : "There are many different different varieties.\n",
 ]) );
  set("objects", ([ MON(man) : 1, ]) );
  set("exits", ([
    "east" : ROOMS(cir_1),  
    "west" : ROOMS(cir_3), 
]) );
 set("pre_exit_func", ([
     "west" : "guarded",
  ]) );
  ::create();  
}
int guarded() {
  if (present("man", TO)) {
    write("The man in black halts your progress to the west.\n");
   return 1;
  }
  write("You step into the circus tent, a chill courses through your veins.\n");
  return 0;
}

  
