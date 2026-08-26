// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The kitchen.");
  set("long", @ENDLONG
You stand in the large kitchen of the Castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
     "south" : ROOMS(kitchen3),
    "west" : ROOMS(mshall3),
    "east" : ROOMS(kitchen2),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
   MON(cook) : random(4) + 1 ,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
