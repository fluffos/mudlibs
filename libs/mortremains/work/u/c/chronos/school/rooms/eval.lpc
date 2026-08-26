// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Default.");
  set("long", @ENDLONG
You stand in a grand hall in the center of Chronos's School of Coding and
Assorted Magicks.
A sign adorns a wall here, catching your eye.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  ]) );
  set("item_desc", ([
    "sign" : "You could maybe even read it if you tried.\n",
  ]) );
  ::create();
}

void init() {
  add_action("read", "read");
}

int read(string str) {
  if (!str) {
    write("Read what?\n");
    return 1;
  }
  if (str != "sign") write("You feel compelled to read the sign instead..\n");
  write(@ENDSIGN
You read:

ENDSIGN
  );
  say(TPN+" stares intently at the sign on the wall for a moment.\n");
  return 1;
}


