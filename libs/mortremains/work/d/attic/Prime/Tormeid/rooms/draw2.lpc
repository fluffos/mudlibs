// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Before the gates of Castle Tormeid.");
  set("long", @ENDLONG
You stand before the massive gates of Castle Tormeid.  Looking in, you
notice that it's quite dark inside the castle, and numerous torches
line the walls, providing light.
Far above you lie two guard stations.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "west" : ROOMS(draw1),
    "east" : ROOMS(main1),
    "north" : ROOMS(grass-n1),
    "south" : ROOMS(grass-s1),
  ]) );
  set("item_desc", ([
   "wall" : "The huge wall surrounds the castle.\n",
  "walls" : "There's only one, really.  A big one.\n",
  "stations" : "You see 2 guard stations on the ramparts above and one inside the gate.\n",
  "gates" : "You stand before the gates.\n",
  "castle" : "The entrance is before you.\n",
  "entrance" : "You stand at the entrance of a grand castle.\n",
  "torches" :"They are in the entranceway.\n",
  "entranceway" : "It's to the east.\n",
  ]) );
  set("exit_msg", ([
  "east" : "$N steps through the castle gates.\n",
  ]) );
  ::create();
}
