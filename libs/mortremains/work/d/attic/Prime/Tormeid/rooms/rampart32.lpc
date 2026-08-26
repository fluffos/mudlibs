// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);
inherit DOORS;

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.");
  set("long", "You stand on the ramparts on the castle wall.
");
  set("light", 1) ;
  set_outside("Light");
  set("exits", ([
    "north" : ROOMS(rampart31.c),
  "west" : ROOMS(uhall15),
    "south" : ROOMS(rampart33.c),
  ]) ) ;
  create_door("west", "east", "A solid iron door with a slit.",
   "closed", "guard_captain", 27) ;
  ::create();
}

