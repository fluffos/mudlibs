#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set_outside("zone","2");
  set("author", "Waxer");
  set("light", 1);
set("short", "The end of the east-west Circus path.");

set("long", @ENDLONG
The main path ends here.  Tents surround you in all directions
housing all sorts of different types of humanoids.  The thick
forest can be seen behind the tents, hovering like a lid to a coffin.
Within the forest you can almost make out a solid structure to the
north, but you can't quite get a good look from your location.
ENDLONG
);

  set("item_desc", ([
    "structure" : "You are much too far away o see it, and see no way to get there.\n",
    "path" : "This path is well-trodden and covered with filthy hay.\n",
 ]) );

  set("objects", ([ MON(clwn) : 1, ]) );
  set("exits", ([
    "east" : ROOMS(cir_8),
]) );
  ::create();
}