inherit ROOM;
#include "../defs.h"
void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
set("short", "The western portion of the circus grounds.");
  
set("long", @ENDLONG
A tent the size of a small home looms over you to the north.  To the
south, an east-west path leads through the circus camp grounds.  You
notice small tents that line the north and south sides of the path you
stand on, they look as though they house the workers and performers
of the Cirque di Mal.  This circus must be quite large indeed.  A sign 
sits on the ground next to the tent's entrance.
ENDLONG
);

  set("item_desc", ([
    "path" : "This path is well-trodden and covered with filthy hay.\n",
    "tent" : "It is a large, white tent with yellow stripes running vertical around it.\n",
 ]) );
  set("exits", ([
    "north" : ROOMS(ptent),  
    "south" : ROOMS(cir_8), 
]) );
  ::create();  
}
