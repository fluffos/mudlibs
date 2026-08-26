// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southwest tower, 2nd floor.");
  set("long", @ENDLONG
You stand on the second level of the southwest tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "east" : ROOMS(rampart56),
    "north" : ROOMS(rampart-6),
    "up" : ROOMS(swtower3),
    "down" : ROOMS(swtower1),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "down" : "$N goes down the stairs.",
    "up" : "$N goes up the stairs.",
  ]) );
  ::create();
}
