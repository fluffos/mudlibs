// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the northeast tower, 2nd floor.");
  set("long", @ENDLONG
You stand on the second floor of the northeast tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "up" : ROOMS(netower3),
    "down" : ROOMS(netower1),
   "west" : ROOMS(rampart23),
    "south" : ROOMS(rampart25),
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
