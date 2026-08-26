#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
A large, dry gorge lies to the southeast.  The battlefield
surrounds you in its gruesome intensity.  The now decayed
corpses of the fallen, caught in their death throes paint
a portrait of a long and desperate battle.  The vegetation
seems to grow thicker to the north, allowing even some
trees to line the path you are standing on.
EndDesc);

set("item_desc", ([ 
     "gorge" : "This is a large, dry gorge, you would have to jump across it.\n",
     "vegetation" : "The forest around the battle has begun to seep back into the area.\n",
     "trees" : "Some small pine and cedar trees have begun to line the path.\n",
]));

set("exits", ([

    "southeast" : ROOMS(b4),
    "north" : ROOMS(b10),

]));

set("pre_exit_func", ([ "southeast" : "foo" ]));

::create();
}
int foo(){
int x;
  x = random(14);
if(x > (int)TP->query("stat/strength")){
                              write("You fall into the gorge below in a failed jump!\n");
                             TP->receive_damage(random(20));
                             TP->move_player(ROOMS(gorge));
                             return 1;
                            }else{ write("You jump across the gorge with a mighty leap!\n"); return 0; }
}
