#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "the dock.");
 	set_outside("zone", "2");
  set("long", @ENDLONG
The dock here is used often.  Piles of rope, nets,
buckets, and other assorted items are here.  The
dock leads north and south.
ENDLONG
   );
  set("item_desc", ([
  "dock" : "The dock is made of wood, and is very small.\n",
  "rope" : "Standard rope used for boats.\n",
  "nets" : "Normal fishing nets...only a little smaller.\n",
  "buckets" :"Bait buckets.\n",
  "piles" : "Piles of fishing equipment.\n"
  ]) );
  set("exits", ([
				"north" : ROOMS(dock2),
				"south" : ROOMS(lake2),
  ]) );
set("objects", ([
    MON(fishmunch) : 1,
  ]) );

  ::create();

}
