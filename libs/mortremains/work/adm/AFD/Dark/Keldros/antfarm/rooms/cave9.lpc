#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);

  set("short", "a niche in the cave.");
  
set("long", @ENDLONG
This is a small niche in the cave.  The walls are
quite rough and jagged.
ENDLONG
   );

  set("item_desc", ([
    "walls" : "It appears as though that the inhabitants of this place haven't mined\nthisfar up the tunnel.\n",
    "wall" : "It appears as though that the inhabitants of this place haven't mined\nthisfar up the tunnel.\n",
]) );
   set("search_desc", ([
     "wall" : "This wall is very rough.\n",
   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air, mixed with a thick\nsteamy smell.\n",
    "wall"  : "You smell the nothing except for rock.\n",
  ]) );
 
  set("exits", ([
    "east" : ROOMS(cave8)
  ]) );
set("objects", ([
    MON(wound) : 1,
]) );
  ::create();

}