// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Outside the castle wall.");
  set("long", @ENDLONG
You stand just south of the main gates of the castle, and right next to 
the moat.  The wall of stone protecting the castle from invaders
rises up next to you, dwarfing the trees across the moat.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
 "north" : ROOMS(draw2),
"south" : ROOMS(grass-s2),
  ]) );
  set("item_desc", ([
  "wall" : "Made of stone and mortar, the wall protects the castle from invaders.\n",
  "gates" :"They are just to the north.\n",
  "moat" :"It's filled with a murky, stagnant water.\n",
  "water" : "You can't see much in it since it is so murky.\n",
  "trees" :"They look small compared to the castle.\n",
  "castle" : "You are just outside the castle wall, beside the moat.\n",
  ]) );
  ::create();
}
