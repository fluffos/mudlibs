// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "A guard station.");
  set("long", @ENDLONG
A small table with two chairs on either side lie in the center of the room,
and a small oil lantern hangs directly above it, providing light.  A windy
little iron-wrought staircase wriggles its way up into the room from the
lower guard station.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "down" : ROOMS(guard_station1),
  "west" : ROOMS(rampart2),
 "south" : ROOMS(uhall1),
  ]) );
  set("exit_msg", ([
   "down" : "$N descends the stairs.",
  ]) ) ;
  set("item_desc", ([
  "table" : "It's quite bare.\n",
  "chairs" : "They are standing near the table.\n",
  "lantern" : "It secured by a chain hanging from the ceiling.\n",
   "staircase" : "It leads down into the lower guard station.\n",
  ]) );
  set("objects", ([
 MON(guard2) : random(4) + 1,
 ]) );
  create_door("south", "north", "It's a strong wooden door.", "open", "--", 40) ;
  ::create();
}
