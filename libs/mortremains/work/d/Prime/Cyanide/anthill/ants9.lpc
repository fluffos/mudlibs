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
  "worker" : MON(worker.c),
  ]) ) ;
  set("exits", ([
    "east" : ROOMS(ants13),
    "north" : ROOMS(ants1),
  ]) ) ;
  ::create();
  reset();
}
/* EOF */
