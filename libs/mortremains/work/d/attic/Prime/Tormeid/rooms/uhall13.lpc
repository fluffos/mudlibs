// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a large hallway on the second floor of the castle.
A large staircase lies to the south.
ENDLONG
  );
  set("light", 1) ;
  set("exits", ([
   "south" : ROOMS(more_stairs2),
  "north" : ROOMS(bedroom19),
    "west" : ROOMS(uhall12.c),
    "east" : ROOMS(uhall14.c),
  ]) ) ;
  ::create();
}
