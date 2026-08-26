// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southeast tower, top floor.");
  set("long", @ENDLONG
You stand on the top floor of the southeast tower in the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "down" : ROOMS(setower4),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "down" : "$N goes down the stairs.",
  ]) );
  ::create();
}
