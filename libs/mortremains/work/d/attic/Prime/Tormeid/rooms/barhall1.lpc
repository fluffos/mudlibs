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
   "south" : ROOMS(barrack1),
   "west" : ROOMS(midhall9) ,
    "east" : ROOMS(barhall2.c),
  ]) ) ;
  ::create();
}
