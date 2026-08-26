#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());
  set("author", "Waxer");  
  set("light", 1);
set("short", "The Clowns' Performance room.");
  
set("long", @ENDLONG
The floor of the tent is surprisingly clean and dry.  The walls
of the tent are burdened with ropes that hold an assortment 
of items ranging from support devices to large leather balls
painted a rainbow of bright colors.  A large platform dominates
the center of the room and a miniature wagon is stationary
beside it.
ENDLONG
);

  set("item_desc", ([
    "platform" : "This platform looks to be a prop for circus performers.\n",
    "path" : "This path is well-trodden and covered with filthy hay.\n",
 ]) );

   set("objects", ([ MON(clwn) : 6, ]) );

  set("exits", ([
    "south" : ROOMS(ptent),
]) );
  ::create();  
}
