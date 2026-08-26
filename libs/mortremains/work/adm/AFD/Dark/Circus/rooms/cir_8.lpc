#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
set("short", "The western portion of the circus grounds.");
  
set("long", @ENDLONG
The main clearing that serves as a path through the circus grounds
has moved to the west.  Small tents powder both sides of the path,
making this look more like a battleground than anything else.  In
the center of the road sits a cylindrical platform colored painted
white with a rainbow of polka-dots covering it.  To the north
is a very large tent with yellow stripes running vertical around the
entire tent.
ENDLONG
);

  set("item_desc", ([
    "platform" : "This platform looks to be a prop for circus performers.\n",
    "path" : "This path is well-trodden and covered with filthy hay.\n",
 ]) );

  set("objects", ([ MON(clwn) : 1, ]) );
  set("exits", ([
    "north": ROOMS(cir_10),
    "west" : ROOMS(cir_9),  
    "east" : ROOMS(cir_5),
    "south" : ROOMS(cir_11),
]) );
  ::create();  
}