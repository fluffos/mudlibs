// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A grand staircase.") ;
  set("long", @ENDLONG
You stand at the top of a magnificient marble staircase leading down to
the lower levels of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(uhall13),
  "down" : ROOMS(more_stairs1),
  ]) );
  set("exit_msg", ([
   "down" : "$N descends the staircase." ,
 ]) ) ;
  set("item_desc", ([
  "stairs" : "They lead up.\n" ,
  ]) );
  ::create();
}
