// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the northeast tower, 3rd floor.");
  set("long", @ENDLONG
You stand on the third floor of the northeast tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "up" : ROOMS(netower4),
    "down" : ROOMS(netower2),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "up" : "$N goes up the stairs.",
    "down" : "$N goes down the stairs.",
  ]) );
  ::create();
}
