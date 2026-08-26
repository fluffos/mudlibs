// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(family_room);

void create() {
  seteuid(getuid());
  set("short", "A guard's home.");
  set("long", @ENDLONG
You are in the home of one of the castle guards.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(Nhall7),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
  reset() ;
}
