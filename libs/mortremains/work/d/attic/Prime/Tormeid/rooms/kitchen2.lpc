// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Back of the kitchen.");
  set("long", @ENDLONG
You are in the back of the kitchen.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(kitchen1),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  "chef" : MON(chef),
  "cook" : MON(cook2),
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
