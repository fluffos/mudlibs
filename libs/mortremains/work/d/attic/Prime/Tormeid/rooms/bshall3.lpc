// This room needs to keep track of its guard to prevent a million guards from
// lagging the mud.  This guard moves about, but this is where it will 
// respawn if it is destroyed.
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
To the east is the Commoners' living areas.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "east" : ROOMS(agdhall1),
  "north" : ROOMS(bshall2),
  "south" : ROOMS(bshall4),
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
