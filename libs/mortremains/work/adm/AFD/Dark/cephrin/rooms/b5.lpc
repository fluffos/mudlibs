#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
The gorge beneath you has been filled with dried
mud and wild vegetation.  To the east lies an endless
battlefield.  The skeletons of the fallen carpet the ground
in an obscene comparison to a burial plot.  They still
remain in their armor, clutching the weapons that led them
to this state of existance.
EndDesc);

set("item_desc", ([ 
                 "skeletons" : "Fallen warriors to an unknown cause lie here like garbage.\n",
                 "armor" : "This armor is completely useless, it has rotten beyond use.\n",
                 "weapons" : "These weapons range from broken bows to dull hand-axes.\n",
]));
set("exits", ([ "west" : ROOMS(b4), ]));
::create();
}
