// This room needs to keep track of its guard.. otherwise it will spawn
// a zillion guards, since this guard wanders about the castle. :D
// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

object guard ;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "west" : ROOMS(museum1),
  "north" : ROOMS(bnhall4),
  "south" : ROOMS(bnhall2),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}

void reset() {
  if (!guard) {
     guard = clone_object(MON(wander_guard)) ;
     guard->move(TO) ;
  }
}
