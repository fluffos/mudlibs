// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Commoner kitchen.");
  set("long", @ENDLONG
This is the kitchen of the Commoner Mess Hall.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(comhall2),
    "east" : ROOMS(comhall3),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
   MON(commoner2) : random(4) + 1,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
