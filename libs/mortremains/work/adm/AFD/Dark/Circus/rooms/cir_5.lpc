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
making this look more like a battleground than anything else.
ENDLONG
);

  set("item_desc", ([
    "path" : "This path is well-trodden and covered with filthy hay.\n",
 ]) );
  set("exits", ([
    "west" : ROOMS(cir_8),  
    "east" : ROOMS(grounds), 
]) );
  ::create();  
}
