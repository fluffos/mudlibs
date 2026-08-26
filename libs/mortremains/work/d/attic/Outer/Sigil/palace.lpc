#include <mudlib.h>
#include "sigil.h"

inherit BUYONLY_SHOP ;

void create() {
  seteuid(getuid());
  ::create() ;
  set("shop_dir", SIGIL+"toys/") ;
  set("restock_msg", @ENDMSG
A rotund little boy runs into the room carrying a small box.
He puts the box behind the counter, giggles, and runs away.
ENDMSG
  );
  set("shopkeeper", "jester") ;
  stock = ([
   "rubber_ducky" : 2 + random(3),
  "watch" : random(2),
   "chronos_doll" : 10,
   "cy_doll" : 10 ,
   "pie" : 5 + random(20) ,
   "nerf" : 1 + random(2),
   "jester_cap" : 1 + random(2),
  ]) ;
  set("objects", ([ "jester" : "/d/Outer/Sigil/monsters/jester" ]) ) ;
  set ("light", 1) ;
  set("short", "The Palace of the Jester.") ;
  set ("long", @ENDLONG
You stand in the Fabled Palace of the Jester in Sigil, home to
some of the strangest and most useless items in all the planes.

A strange, multi-colored staircase spirals up into the ceiling here.

Commands are: list, buy <item>
ENDLONG
  );
  set("exit_msg", ([
    "up" : "$N climbs the multi-color staircase.",
  ]) ) ;
  set("exits", ([
    "up" : SIGIL+"palace1",
    "west" : SIGIL+"ladyst1",
  ]) ) ;
  reset();
}
