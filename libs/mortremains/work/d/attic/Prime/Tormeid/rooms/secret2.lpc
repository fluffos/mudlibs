// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A secret passage.");
  set("long", @ENDLONG
You stand in a secret passage in the Castle.
A secret door is to the west.
ENDLONG
  );
  set("light", 0);
  set("exits", ([
    "west" : ROOMS(kingroom1),
    "down" : ROOMS(secret1),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "down" : "$N descends the stairs.",
    "west" : "$N leaves through the secret door to the west.",
  ]) );
  ::create();
}
