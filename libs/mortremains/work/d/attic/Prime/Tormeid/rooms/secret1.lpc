// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A secret passageway.");
  set("long", @ENDLONG
You are in a secret passageway behind the King's study.
There is a secret door to the south.
ENDLONG
  );
  set("light", 0);
  set("exits", ([
   "up" : ROOMS(secret2),
    "south" : ROOMS(study),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  "south" : "$N leaves through the secret door to the south.",
  "up" : "$N ascends the stairs.",
  ]) );
  ::create();
}
