// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Outside the castle wall.");
  set("long", @ENDLONG
You stand just north of the drawbridge of the Castle Tormeid, on the grass
outside the fortress walls.  The murky waters of the moat lap gently 
at the bank to the west.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "north" : ROOMS(grass-n2),
    "south" : ROOMS(draw2),
  ]) );
  set("item_desc", ([
  "bridge" : "The drawbridge is to the south.\n",
  "drawbridge" :"The drawbridge is to the south.\n",
  "water" : "The water looks rather stagnant.\n",
  "moat" : "The water looks rather stagnant.\n",
  "castle" : "You stand outside the Castle Tormeid.\n",
  "walls" : "You stand just outside the fortress walls.\n",
  "waters" : "The moat looks really dirty.\n",
  ]) );
  ::create();
}
