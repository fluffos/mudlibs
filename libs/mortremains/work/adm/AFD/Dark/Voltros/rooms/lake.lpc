#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "A lake.") ;
	set_outside("zone", "2");
  set("long", @ENDLONG
This is a brilliant azure lake.  It isn't very big as far as
lakes go, but it's decently sized.  The water is a deep blue hue,
and the surrounding foliage is also bright in color.  To the east,
a dock can be seen.  South, a hut is peeking through the trees.
The town is to the west, and to the north, the lake continues onward.
 
ENDLONG
   );
  set("item_desc", ([
  "lake" : "Light dances off the surface of the lake.\n",
  "foliage" : "The plant life here is vibrant in color\n",
		"dock" : "The dock is jutting out from the shore about 20 feet.\n",
		"hut" : "It looks like a boathouse.\n",
		"town" : "The munchkin town can be seen to the west.\n", 
   ]) );
  set("exits", ([
    "east" : ROOMS(lake2),
				"west" : ROOMS(tsquare),
				"south" : ROOMS(boathouse),
				"north" : ROOMS(lake3),
  ]) );
set("objects", ([
    MON(munchkin) : 1,
  ]) );

  ::create();

}
