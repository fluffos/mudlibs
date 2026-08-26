// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the bottom of the northeast tower.");
  set("long", @ENDLONG
You stand on the bottom floor of the northeast tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "west" : ROOMS(Nhall1),
   "south" : ROOMS(Ehall15),
    "up" : ROOMS(netower2),
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
