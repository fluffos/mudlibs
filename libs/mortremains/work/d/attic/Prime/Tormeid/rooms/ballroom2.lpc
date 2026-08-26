// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A massive ballroom.");
  set("long", @ENDLONG
You stand in the massive ballroom of the Castle Tormeid.  This is where
the King holds all ceremonies and parties when he's in a festive mood.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "east" : ROOMS(mshall4),
    "north" : ROOMS(ballroom1),
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
