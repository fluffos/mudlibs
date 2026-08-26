#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 0);
  set("short", "in a cramped tunnel.");
  set("long", @ENDLONG
The walls of the cave are completely smooth, apparently
mined to depletion.
ENDLONG
   );
  set("item_desc", ([
  "walls" : "The walls appear to have been crafted with rough instruments,
as a result of what appears to be mining.\n",
    "wall" : "The walls appear to have been crafted with rough instruments,
as a result of what appears to be mining.\n",
  ]) );
  set("search_desc", ([
     "wall" : "This wall is completely smooth.\n",
  ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air, and the smell of rotten
flesh.\n",
    ]) );
  set("objects", ([ MON(slave) : 2, MON(workant) : 1, ]));
  set("listen", ([ "default" : "You hear a light clicking sounds.\n", ]) );
  set("exits", ([
    "west" : ROOMS(cave6.c),
    "southwest" : ROOMS(cave1),
  ]) );
  ::create();
}

