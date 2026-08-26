#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "a lake.");
 	set_outside("zone", "2");
  set("long", @ENDLONG
The path continues on to the north, south, and west.
The north, is a dock.  The south, is a path further
into the town.  And the west, is also further into
town.
ENDLONG
   );
  set("item_desc", ([
  "shoreline" : "The shoreline is lush and green.\n",
  "dock" : "The dock is made of wood, and is very small.\n",
  "town" : "The munchkin town can be seen from here.\n",
   ]) );
  set("exits", ([
				"west" : ROOMS(lake),
				"north" : ROOMS(dock),
				"south" : ROOMS(path_1),
  ]) );
set("objects", ([
    MON(munchkin) : 1,
  ]) );

  ::create();

}
