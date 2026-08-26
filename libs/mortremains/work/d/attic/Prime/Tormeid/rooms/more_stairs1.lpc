// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A grand staircase.") ;
  set("long", @ENDLONG
You stand at the bottom of a magnificient marble staircase leading up to
the second level of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "up" : ROOMS(more_stairs2),
  ]) );
  set("exit_msg", ([
  "up" : "$N ascends the staircase.",
 ]) ) ;
  set("item_desc", ([
  "stairs" : "They lead up.\n" ,
  ]) );
  ::create();
}
