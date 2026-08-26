// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A massive ballroom.");
  set("long", @ENDLONG
You stand in a massive ballroom in the Castle Tormeid.  This is where
the King holds all ceremonies and parties when he is in the festive
mood.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "south" : ROOMS(ballroom2),
    "east" : ROOMS(mshall3),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(servant) : random(4),
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
