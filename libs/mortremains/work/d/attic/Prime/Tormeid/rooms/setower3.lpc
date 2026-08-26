// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southeast tower, 3rd floor.");
  set("long", @ENDLONG
You stand on the third floor of the southeast tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "down" : ROOMS(setower2),
    "up" : ROOMS(setower4),
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
