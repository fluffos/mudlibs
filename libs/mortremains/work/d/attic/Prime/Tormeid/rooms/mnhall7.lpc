// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In a large hallway.");
  set("long", @ENDLONG
The large hallway ends here, but splits into two smaller hallways running
east and west through the northmost part of the castle, beneath the ramparts.
ENDLONG
  ) ;
  set("light", 1) ;
  set("exits", ([
   "west" : ROOMS(Nhall14),
   "east" : ROOMS(Nhall12),
    "south" : ROOMS(mnhall6.c),
  ]) ) ;
  ::create();
}
