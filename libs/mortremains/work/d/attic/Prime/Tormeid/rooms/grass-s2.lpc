// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Outside the castle wall.");
  set("long", @ENDLONG
You stand outside of the castle wall, between the hard stone and murky
moat.  The ground here has quite a bit of loose stone and mortar about.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
  "north" : ROOMS(grass-s1),
  "south" : ROOMS(grass-s3),
  ]) );
  set("item_desc", ([
  "mortar" : "It's the substance that was holding the wall together.  Some of it seems to\nhave cracked and broke from the wall.\n",
  "stone" : "It appears to be pieces of the wall broken off.\n",
  "ground" : "The ground is covered with mortar and stone.\n",
  "moat" :"It's quite murky down there.\n",
  "wall" :"It protects the castle from invasion.\n",
  "castle" : "You stand just outside the castle walls.\n",
  ]) );
  ::create();
}
