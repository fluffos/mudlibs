// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Entrance to the courtyard.");
  set("long", @ENDLONG
You stand in the entrance to the castle's courtyard.  There is a 
guard station to the north and the courtyard opens up to the
east.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(guard_station1),
   "west" : ROOMS(draw2),
    "east" : ROOMS(courtyard1),
  ]) );
  set("item_desc", ([
  "courtyard" : "It opens up to the east.\n",
  "yard" : "It opens up to the east.\n",
  "station" : "Guards perform their duties in the guard station.\n",
  "castle" : "You are in the entranceway to the castle, beneath the ramparts.\n",
  "ramparts" :"You see small holes in the ramparts above you.\n",
  "holes" :"You imagine someone could drop things on you from above with them.\n",
  ]) );
  set("exit_msg", ([
  "west" : "$N leaves through the castle gates.\n",
  ]) );
  ::create();
}
