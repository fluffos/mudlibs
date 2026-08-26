// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A Dank Dungeon.");
  set("long", "You are in a long, dark dungeon corridor.\nThe air down here is stale and moist.\n
");
  set("light", 0) ;
  set("exits", ([
    "south" : D(dungeon5.c),
    "north" : D(dungeon7.c),
  ]) ) ;
  ::create();
}


