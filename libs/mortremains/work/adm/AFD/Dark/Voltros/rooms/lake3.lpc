#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "a lake.");
 	set_outside("zone", "2");
  set("long", @ENDLONG
Here, the shoreline runs north-south here.  North of here, a
calm, shady spot can be seen.  South, the lake continues.
ENDLONG
   );
  set("item_desc", ([
  "shoreline" : "The shoreline is lush and green.\n",
  "spot" : "A nice spot to fish, it would seem.\n",
   ]) );
  set("exits", ([
				"south" : ROOMS(lake),
				"north" : ROOMS(lake4),
  ]) );
set("objects", ([
    MON(munchkin) : 2,
  ]) );

  ::create();

}
