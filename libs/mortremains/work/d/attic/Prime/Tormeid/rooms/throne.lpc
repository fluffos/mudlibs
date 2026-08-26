// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The throne room.") ;
  set("long", @ENDLONG
You stand in a grand audience chamber in the castle.  Magnificient
tapestries cover the walls and an even more magnificient throne
rests by the east wall.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "west" : ROOMS(hall3),
  "north" : ROOMS(study),
  "south" : ROOMS(office),
  ]) );
  set("item_desc", ([
  "tapestries" : "They are affixed to the wall permanently.\n",
   "throne" : "There is no one sitting in it currently.\n",
  "wall" : "The wall is covered with a magnificient tapestry.\n",
   "walls" : "The walls are covered with a magnificient tapestry.\n",
  ]) );
  set("objects", ([
  MON(royal_guard) : 4,
 ]) );
  ::create();
}
