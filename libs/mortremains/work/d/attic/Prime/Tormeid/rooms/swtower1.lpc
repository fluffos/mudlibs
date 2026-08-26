// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southwest tower.");
  set("long", @ENDLONG
You stand at the bottom of the southwest tower in the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "east" : ROOMS(Shall1),
    "up" : ROOMS(swtower2),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "up" : "$N goes up the stairs.",
  ]) );
  ::create();
}
