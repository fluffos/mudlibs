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
  "north": ROOMS(cbedroom18),
  "south": ROOMS(cbedroom19),
    "west" : ROOMS(cs-hall5.c),
  ]) ) ;
  ::create();
}
