// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large staircase.");
  set("long", @ENDLONG
This is the commoners' staircase on the first level of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "west" : ROOMS(Shall2),
   "east" : ROOMS(Shall4),
   "north" :ROOMS(mshall6),
  "up" : ROOMS(s_stairs-2),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  "up" : "$N ascends the stairs.",
  ]) );
  ::create();
}
