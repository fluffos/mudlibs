// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Outside the castle wall.");
  set("long", @ENDLONG
You stand on the grassy bank just beyond the protection of the castle
wall.  The moat is directly to the west.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
  "south" : ROOMS(grass-n1),
  "north" : ROOMS(grass-n3),
  ]) );
  set("item_desc", ([
  "wall" : "The castle wall rises high above you.\n",
  "castle" :"You stand just outside of the castle walls.\n",
  "moat" : "The waters look rather stagnant.\n",
  "water" :"The water looks rather stagnant.\n",
 "bank" : "You stand on a grassy bank beside the moat.\n",
  ]) );
  ::create();
}
