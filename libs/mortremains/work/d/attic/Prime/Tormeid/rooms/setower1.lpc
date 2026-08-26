// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the bottom of the southeast tower.");
  set("long", @ENDLONG
You stand on the bottom floor of the southeast tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(Ehall1),
    "west" : ROOMS(Shall15),
    "up" : ROOMS(setower2),
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
