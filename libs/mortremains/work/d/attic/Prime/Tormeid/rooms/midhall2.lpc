// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway in the castle.");
  set("long", "This large hallway runs north and south through the center of the castle.\n");
  set("light", 1) ;
  set("exits", ([
  "east": ROOMS(family1),
   "west" : ROOMS(family2),
    "south" : ROOMS(midhall1.c),
    "north" : ROOMS(midhall3.c),
  ]) ) ;
  ::create();
}
