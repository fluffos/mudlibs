// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The base of the northwest tower.");
  set("long", @ENDLONG
You stand at the base of the northwest tower of the castle.
High above, you can hear the wind ruffling one of the many flags
adorning the castle towers.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "south" : ROOMS(grass-n4),
  ]) );
  set("item_desc", ([
 "towers" : "There are four.  You stand at the northwestern tower.\n",
  "base" :"You stand at the base of the northwest tower.\n",
  "tower" :"It rises high above you.\n",
  "walls" :"They rise high above you.\n",
  "flags" : "You can't see them, but you can hear them.\n",
  ]) );
  set("listen", ([
  "default" : "You hear flags flapping far above you.\n",
  ]) );
  ::create();
}
