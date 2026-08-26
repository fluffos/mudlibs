// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", "You stand in a large hallway on the second floor of the castle.
");
  set("light", 1) ;
  set("exits", ([
   "north" : ROOMS(bedroom16),
    "south" : ROOMS(bedroom15),
  "west" : ROOMS(uhall10),
    "east" : ROOMS(uhall12.c),
  ]) ) ;
  ::create();
}
