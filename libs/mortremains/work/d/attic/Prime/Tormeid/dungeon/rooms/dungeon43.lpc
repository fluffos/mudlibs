// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A Dank Dungeon.");
  set("long", "You arein a long, dark dungeon corridor.\nThe air down here is stale and moist.\n
");
  set("light", 1) ;
  set("exits", ([
    "west" : D(dungeon42.c),
    "east" : D(dungeon44.c),
  ]) ) ;
  ::create();
}


