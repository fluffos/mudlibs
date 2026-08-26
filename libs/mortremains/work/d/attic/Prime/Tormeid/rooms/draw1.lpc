// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The drawbridge to Tormeid Castle.");
  set("long", @ENDLONG
You stand on a massive wooden drawbridge leading into the Castle Tormeid.
To the west lies a vast expanse of forest, to the east is the castle
entrance.  High above the gates, you see a guard station on either side
of the entrance.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
   "west" : ROOMS(draw1),
    "east" : ROOMS(draw2),
  ]) );
  set("item_desc", ([
  "spires" : "Towards the back of the castle there are some large spires jutting into the\nsky above.\n",
  "moat" : "It's below you.  You think you see some tentacled beast writhing about in it.\n",
  "beast" : "You aren't even really sure it's what you think it is.\n",
   "towers" :"There is a tower at each corner of the castle.\n",
  "castle" : @ENDCASTLE
Magnificient spires reach up into the sky above, and 4 towers reest at
each corner of the fortress.  A thick moat surrounds the castle, protecting
it from invading forces.  A giant drawbridge is the only passage across
the moat that is visible, and you stand on it.
ENDCASTLE
  ,
  "drawbridge" : "You are standing on the lowerered drawbridge to the castle.\n",
  "bridge" : "You are standing on the lowered drawbridge.\n",
  "forest" : "To the west lies a vast expanse of forest.\n",
   "station" : "There are guard stations on either side of the gates.\n",
  "gates" : "They lead into the fortress.\n",
  "entrance" : "It leads into the fortress.\n",
  "stations" : "There is one on either side of the gates.\n",
  ]) );
  ::create();
  call_other(OBJ(tormeid_board),"foo") ;
}

void init() {
  add_action("east", "go") ;
}

int east(string str) {
  if (str != "west") return 0 ;
  if (!userp(TP)) return 0 ;
  write("Everything seems to shift and swirl around you..\n") ;
  TP->move_player("/d/Outer/Sigil/trioptic") ;
  return 1;
}
