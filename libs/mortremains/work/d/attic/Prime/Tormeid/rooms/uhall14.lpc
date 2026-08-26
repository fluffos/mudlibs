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
  "north" : ROOMS(bedroom21),
 "south" : ROOMS(bedroom20),
    "west" : ROOMS(uhall13.c),
    "east" : ROOMS(uhall15.c),
  ]) ) ;
  ::create();
}
