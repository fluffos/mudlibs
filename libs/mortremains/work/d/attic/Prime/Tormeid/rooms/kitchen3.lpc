// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The kitchen.");
  set("long", @ENDLONG
You are in the kitchen of the Castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(kitchen1),
    "west" : ROOMS(mshall4),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(cook) : random(3) + 1,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
