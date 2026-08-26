// Coded by Chronos.
#include <mudlib.h>

object servant ;
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In a large hallway.");
  set("long", "This large hallway runs north and south through the castle.
");
  set("light", 1) ;
  set("exits", ([
    "south" : ROOMS(mnhall5.c),
    "north" : ROOMS(mnhall7.c),
  ]) ) ;
  ::create();
}

void reset() {
   if (!servant) {
     servant = clone_object(MON(moving_servant)) ;
     servant->move(TO) ;
  }
  ::reset() ;
}
