// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In a large hallway.");
  set("long", "This large hallway runs north and south through the castle.
");
  set("light", 1) ;
  set("exits", ([
    "south" : ROOMS(mnhall4.c),
    "north" : ROOMS(mnhall6.c),
  ]) ) ;
  ::create();
}
