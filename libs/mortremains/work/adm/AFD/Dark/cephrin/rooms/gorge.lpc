#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
The bottom of the gorge is powdered with weeds and plants
of all kinds. The gorge is blocked to the east and west
and all that surrounds you save for the local plant life
are boulders on the south side of the gorge.
EndDesc);

set("item_desc", ([ 
    "plant life" : "Weeds and small plants of many varieties make thier homes here.\n",
    "boulders" : "It appears as though you could climb back up using them.\n",
]));

set("exits", ([

]));

::create();
}
void init(){
  add_action("climb", "climb");
}
int climb(){
  int x;
   x = random(12);
if((string)TP->query("guild")=="Thief"){
    write("Your thief skills work well for you in scaling the wall.\n");
    TP->move_player(ROOMS(b4));
    return 1;
}
if(x > (int)TP->query("stat/agility")){
    write("You fail to scale the rock wall.\n");
return 1;
}else{ write("You scale the wall successfully.\n"); TP->move_player(ROOMS(b4)); return 1; }
}