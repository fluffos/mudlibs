// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You stand in a narrow hallway on the north side of the castle.\n");
  set("light", 1) ;
  set("exits", ([
   "south" : ROOMS(midhall15),
    "east" : ROOMS(Nhall8.c),
    "west" : ROOMS(Nhall10.c),
  ]) ) ;
  ::create();
}
