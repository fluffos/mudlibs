// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The west side of the track.");
  set("long", @ENDLONG
You stand on the west side of a mile-long track used for PT on the base.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(plot4),
    "east" : ROOMS(track2),
  ]) ) ;
  ::create();
  reset();
}
