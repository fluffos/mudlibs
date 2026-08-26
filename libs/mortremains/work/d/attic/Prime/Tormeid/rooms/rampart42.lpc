// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.");
  set("long", "You stand on the ramparts of the castle wall.
");
  set("light", 1) ;
  set_outside("Light");
  set("exits", ([
   "east" : ROOMS(setower2),
    "west" : ROOMS(rampart43.c),
  ]) ) ;
  ::create();
}
