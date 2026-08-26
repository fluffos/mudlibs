// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "An audience room.") ;
  set("long", @ENDLONG
You stand in the audience room of the castle, where people wait to
have an audience with the King.  There are many comfortable chairs
lining the walls here, and some magnificient artworks hanging
above them.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "west" : ROOMS(hall2),
  "east" : ROOMS(throne),
  ]) );
  set("item_desc", ([
   "artworks" : "They are all probably worth a small fortune.\n",
   "chairs" : "They look very comfortable.\n",
  ]) );
  set("objects", ([
  MON(door_guard1) : 2,
 ]) );
  ::create();
}
