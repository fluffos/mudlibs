#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "the dock.");
 	set_outside("zone", "2");
  set("long", @ENDLONG
Here, a large net lies on the edge of the dock.  
Offshore, you can hear an arguement about somthing.
ENDLONG
   );
  set("item_desc", ([
  	"dock" : "The dock is made of wood, and is very small.\n",
  
  ]) );
  set("listen", ([
  	"default" : "You are a dumbass....you left the net...No I didn't!  YOU did!\n",
]) );
 set("exits", ([
				"south" : ROOMS(dock),
  ]) );
set("objects", ([
    MON(crab) : 1,
  ]) );
  ::create();

}
