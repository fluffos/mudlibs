// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Commoners' Hall South.");
  set("long", "You stand in the Commoners' Hall, where all the servants and workers live.
");
  set("light", 1) ;
  set("exits", ([
   "north" : ROOMS(cbedroom15),
  "south" : ROOMS(cbedroom22),
    "west" : ROOMS(cs-hall2.c),
    "east" : ROOMS(cs-hall4.c),
  ]) ) ;
  ::create();
}
