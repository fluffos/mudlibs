// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You are in a narrow hallway running north through the castle.\n");
  set("light", 1) ;
  set("exits", ([
  "west" : ROOMS(barhall6),
    "south" : ROOMS(Ehall8.c),
    "north" : ROOMS(Ehall10.c),
  ]) ) ;
  ::create();
}
