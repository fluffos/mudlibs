// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The barracks.");
  set("long", "You are in the barracks, home to all guards and guard trainees.\n");
  set("light", 1) ;
  set("exits", ([
   "north" : ROOMS(barrack4),
   "south" : ROOMS(training3),
    "west" : ROOMS(barhall3.c),
    "east" : ROOMS(barhall5.c),
  ]) ) ;
  ::create();
}
