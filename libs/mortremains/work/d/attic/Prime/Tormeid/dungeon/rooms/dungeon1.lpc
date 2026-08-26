// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A Dank Dungeon.");
  set("long", "You are in a long, dark dungeon corridor.\nThe air down here is stale and moist.\n
A dank staircase leads up into the ceiling here.\n") ;
  set("light", 0) ;
  set("exits", ([
   "up" : ROOMS(guard_storage2),
  "north" : D(dungeon2) ,
  ]) ) ;
  ::create();
}
