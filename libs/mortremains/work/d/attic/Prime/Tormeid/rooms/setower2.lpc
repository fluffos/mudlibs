// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southeast tower, 2nd floor.");
  set("long", @ENDLONG
You stand on the second floor of the southeast tower in the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "up" : ROOMS(setower3),
    "down" : ROOMS(setower1),
    "north" : ROOMS(rampart39),
  "west" : ROOMS(rampart42),
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
