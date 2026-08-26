// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Bottom of the northwest tower.");
  set("long", @ENDLONG
You stand at the bottom of the northwest tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "east" : ROOMS(Nhall15),
    "up" : ROOMS(nwtower2),
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
