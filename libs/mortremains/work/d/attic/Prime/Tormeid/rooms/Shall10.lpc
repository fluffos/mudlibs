// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You stand in a long, narrow hallway on the south side of the castle.\n");
  set("light", 1) ;
  set("exits", ([
  "north" : ROOMS(family21),
    "west" : ROOMS(Shall9.c),
    "east" : ROOMS(Shall11.c),
  ]) ) ;
  ::create();
}
