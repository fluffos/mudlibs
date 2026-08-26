// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "In the southeast tower, 4th floor.");
  set("long", @ENDLONG
You stand on the fourth floor of the southeast tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "down" : ROOMS(setower3),
    "up" : ROOMS(setower5),
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
