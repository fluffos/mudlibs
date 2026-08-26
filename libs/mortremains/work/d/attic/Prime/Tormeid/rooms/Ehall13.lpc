// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You are in a narrow hallway running north through the castle.\n");
  set("light", 1) ;
  set("exits", ([
    "south" : ROOMS(Ehall12.c),
    "north" : ROOMS(Ehall14.c),
  ]) ) ;
  ::create();
}
