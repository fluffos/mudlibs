// (A)nother (G)od (D)amned (H)all.
// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Commoners' Hall North.") ;
  set("long", "You stand in a large hallway on the second floor of the castle.
");
  set("light", 1) ;
  set("exits", ([
  "north" : ROOMS(cbedroom1),
  "south" : ROOMS(cbedroom12),
  "west" : ROOMS(bshall3),
    "east" : ROOMS(agdhall2.c),
  ]) ) ;
  ::create();
}
