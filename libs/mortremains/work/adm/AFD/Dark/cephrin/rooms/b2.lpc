#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
The battlefield that surrounds you is quite impressive indeed.
Skeletons of all races litter the ground as if in a waste storage
area, they number in the hundreds and perhaps thousands.  Most
of the skeletons are clothed in rusted and decayed armor.
EndDesc);

set("item_desc", ([ 
                 "skeletons" : "Fallen warriors to an unknown cause lie here like garbage.\n",
                 "armor" : "This armor is completely useless, it has rotten beyond use.\n",
]));

set("exits", ([
     "north" : ROOMS(b4),
     "south" : ROOMS(bat),
     "east" : ROOMS(b1),
]));

::create();
}
