#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
A deep gorge lies to the southwest, a dried testament to the
destruction of this area.  Skeletons clothed in armor litter
the surroundings.  A single tall oak tree stands here brooding
over the scene.
EndDesc);

set("objects", ([ MON(lieu) : 1, MON(warrior) : 2 ]));
set("item_desc", ([ 
                 "skeletons" : "Fallen warriors to an unknown cause lie here like garbage.\n",
                 "armor" : "This armor is completely useless, it has rotten beyond use.\n",
                 "weapons" : "These weapons range from broken bows to dull hand-axes.\n",
                 ({ "oak", "tree", "oak tree" }) : "This is a tall oak tree, surprisingly still alive and growing.\n",
]));
set("exits", ([ "southwest" : ROOMS(b4), "north" : ROOMS(b11), "east" : ROOMS(b9) ]));
::create();
}