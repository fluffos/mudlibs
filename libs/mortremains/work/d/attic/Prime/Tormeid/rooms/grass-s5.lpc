// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "At the base of the southwestern tower.");
  set("long", @ENDLONG
You stand at the base of one of the four towers at each corner of the
castle.  Far above you, you can barely make out some flags flapping
around in the breeze.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "north" : ROOMS(grass-s4),
  ]) );
  set("listen", ([
    "default" : "You can hear the flapping of a flag in a strong breeze.\n",
  ]) );
  set("item_desc", ([
  ]) );
  ::create();
}
