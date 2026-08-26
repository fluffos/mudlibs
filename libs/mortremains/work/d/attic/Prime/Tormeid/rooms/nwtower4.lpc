// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "In the northwest tower, 4th floor.");
  set("long", @ENDLONG
You stand in the northwest tower on the fourth floor.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "down" : ROOMS(nwtower3),
    "up" : ROOMS(nwtower5),
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
