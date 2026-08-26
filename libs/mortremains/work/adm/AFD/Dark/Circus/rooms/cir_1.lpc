#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside("zone", "2");
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The entrance to a circus.");
  
set("long", @ENDLONG
The rocky path has met softer ground.  The brush has been cleared away
to the west, forming a ring.  You see in the center of the ring a very large
tent with a small red flag on the very top.  From this point you can see
a small path leading off to the north and the south, as well as continuing
west to the tent or east to the weed-ridden path.
ENDLONG
);

  set("item_desc", ([
    "tent" : "The tent is perhaps three hundred feet in diameter.  The tent is
colored white, with gigantic red stripes that run verticle along all sides
of it.  You would assume it is a circus tent.\n",
    "flag" : "There are many different different varieties.\n",
    
 ]) );
  set("objects", ([ OBJ(wagon) : 1, ]) );
  set("exits", ([
    "north" : ROOMS(grounds),
    "south" : ROOMS(an_1),
    "out" : ROOMS(camp),  
    "west" : ROOMS(cir_2),  
    "enter" : ROOMS(wag1),
]) );
  set("exit_suppress", ({ "enter" }) );
  ::create();  
}
