// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A Dank Dungeon.");
  set("long", "You arein a long, dark dungeon corridor.\nThe air down here is stale and moist.\n
A dark little staircase winds its way down into darkness.
");
  set("light", 1) ;
  set("exits", ([
    "west" : D(dungeon52.c),
  "down" : BASE + "catacombs/rooms/catacombs-1",
  ]) ) ;
  set("exit_msg", ([
   "down" : "$N descends into the darkness below.", 
  ]) ) ;
  ::create();
}


