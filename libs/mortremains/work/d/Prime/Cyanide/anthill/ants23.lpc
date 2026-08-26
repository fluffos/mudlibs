// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In a tunnel.");
  set("long", "You are in one of the endless tunnels in the gigantic anthill.  All the\ntunnels seem to look alike, and you feel as though you might get lost if\nyou aren't careful.\n");
  set("light", 1) ;
  set("objects", ([
    MON(worker) : 2 ,
  ]) ) ;
  set("exits", ([
    "south" : ROOMS(ants21),
    "east" : ROOMS(ants15),
    "west" : ROOMS(ants1),
  ]) ) ;
  ::create();
  reset();
}
/* EOF */
