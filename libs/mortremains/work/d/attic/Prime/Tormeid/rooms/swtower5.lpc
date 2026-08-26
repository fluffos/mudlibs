// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the southwest tower, top floor.");
  set("long", @ENDLONG
You stand at the top level of the southwest tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "down" : ROOMS(swtower4),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  "princess" : MON(princess),
  "guard" : MON(guard4),
  ]) );
  set("exit_msg", ([
    "down" : "$N goes down the stairs.",
  ]) );
  ::create();
}
