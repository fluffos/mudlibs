// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large staircase.");
  set("long", @ENDLONG
This is the commoners' staircase on the second level of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "down" : ROOMS(s_stairs-1),
    "north" : ROOMS(bshall6),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
   "down" : "$N descends the stairs.",
  ]) );
  ::create();
}
