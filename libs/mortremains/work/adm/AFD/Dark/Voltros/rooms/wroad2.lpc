#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "A forest clearing.");
	set_outside("zone", "2");
set("long", @ENDLONG
About 30 feet from the path, a campfire can be seen
in the center of the clearing.  Bedrolls and cooking
utensils are strewn about the area.
ENDLONG
   );

  set("item_desc", ([
  "campfire" : "The fire burns a deep orange color.\n",
  "bedrolls" : "The bedrolls are unrolled, ready to be slept on.\n",
  "utensils" : "The utensils are full of food.\n"
		]) );
  set("exits", ([
    "east" : ROOMS(wroad),
    "west" :  ROOMS(mono)
  ]) );

set("objects", ([
    MON(heretic) : 1,
				MON(follower) : 4,
				MON(horse) : 5,
  ]) );
  ::create();
}