// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southwest tower, 3rd floor.");
  set("long", @ENDLONG
You stand in the southwest tower on the third floor.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "up" : ROOMS(swtower4),
    "down" : ROOMS(swtower2),
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
