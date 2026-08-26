#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "A forest path.");
	set_outside("zone", "2");
set("long", @ENDLONG
You are on a plain forest path.  To the west, you can see a
campfire of some type.  To the east, a weather-beaten path
can be seen leading north and south.
ENDLONG
   );

  set("item_desc", ([
  "path" : "The path has little footprints all over it.\n",
    "campfire" : "The fire crackles and spits a little.\n",
   ]) );
  set("exits", ([
    "east" : ROOMS(outskirts),
    "west" :  ROOMS(wroad2)
  ]) );
  ::create();
}