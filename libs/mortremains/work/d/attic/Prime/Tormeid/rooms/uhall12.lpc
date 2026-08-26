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
  "north" : ROOMS(bedroom18),
  "south" : ROOMS(bedroom17),
    "west" : ROOMS(uhall11.c),
    "east" : ROOMS(uhall13.c),
  ]) ) ;
  ::create();
}
