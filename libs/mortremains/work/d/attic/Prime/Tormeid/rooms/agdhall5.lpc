// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Commoners' Hall North.") ;
  set("long", "You stand in a large hallway on the second floor of the castle.
");
  set("light", 1) ;
  set("exits", ([
 "north" : ROOMS(cbedroom5),
 "south" : ROOMS(cbedroom8),
    "west" : ROOMS(agdhall4.c),
    "east" : ROOMS(agdhall6.c),
  ]) ) ;
  ::create();
}
