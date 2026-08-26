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
  "north" : ROOMS(barrack6),
   "east" : ROOMS(Ehall9),
    "west" : ROOMS(barhall5.c),
  ]) ) ;
  ::create();
}
