// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "A large hallway in the castle.");
  set("long", "This large hallway runs north and south through the center of the castle.\n");
  set("light", 1) ;
  set("exits", ([
   "east" : ROOMS(barhall1),
    "south" : ROOMS(midhall8.c),
    "north" : ROOMS(midhall10.c),
  ]) ) ;
  ::create();
}
