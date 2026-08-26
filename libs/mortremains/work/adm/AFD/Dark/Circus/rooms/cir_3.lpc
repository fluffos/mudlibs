#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());
  set("author", "Waxer");  

  set("light", 1);

  set("short", "In the Big top.");
  
set("long", @ENDLONG
The "Big Top" is enormous.  Wooden benches line the circular
interior supported by metal frames and surrounding a black circle
in the center. The center circle is made of jet black dirt, yet
looks to be where the main attractions of the circus are displayed.
ENDLONG
);

  set("item_desc", ([
    "tent" : "The tent is perhaps three hundred feet in diameter. The tent is
colored white, with gigantic red stripes that run verticle along all sides
of it.  You would assume it is a circus tent.\n",
    "dirt" : "This dirt is deffinitely not native to this area.\n",
 "circle" : "When the circus is performing, this is where the main attraction
takes place.\n",
 "benches" : "These are for the spectators of the Cirque Di Mal.\n",
 "frames" : "These are old frames that support wooden benches.\n",
 ]) );
  set("objects", ([ MON(ringmaster) : 1, ]) );
  set("exits", ([
    "east" : ROOMS(cir_2), 
]) );
  ::create();  
}
