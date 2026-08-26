#include "../defs.h"
int pushed;
int moved;
inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Waxer");

  set("light", 0);


  set("short", "A collapsed tunnel.");

set("long", @ENDLONG
 This portion of the cave has collapsed.  Other than a huge pile of rubble 
 that rests in the center, this room has nothing of interest.
ENDLONG
   );

  set("item_desc", ([
  "rubble" : "It appears that the rubble could be hiding something underneath it.\n",
    "wall" : "These walls have been mined bare and cut smooth.\n",






                     ]) );
   set("search_desc", ([
     "wall" : "This wall is completely smooth.\n",
     "rubble" : "You see a hole underneath th rubble, perhaps you should
[push rocks] to find out where it leads.\n",
   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    "wall"  : "You smell the nothing except for rock.\n",
]) );
  set("exits", ([
   "east" : ROOMS(further),
                ]) );
::create();
}
void init(){

add_action("move","move");
add_action("push", "push");
}



int push(string str) {
  if (!str) return 0;
  if(pushed)
  {
   write("The rocks have already been pushed aside.\n");
  }
  if (str != "rocks" && str != "rubble" && str != "rock") return 0;
  write("As you push the rocks aside, you lose your balance and fall in the hole!\n");
  TP->move_player(ROOMS(l1));
  add_exit("down", ROOMS(l1));  
return 1;
pushed = 1;
}
int move(string str) {
  if (!str) return 0;
  if(moved)
  {
   write("The rocks have already been pushed aside.\n");
  }
  if (str != "rocks" && str != "rubble" && str != "rock") return 0;
  write("As you push the rocks aside, you lose your balance and fall in the hole!\n");
  TP->move_player(ROOMS(l1));
  add_exit("down", ROOMS(l1));
  return 1;
  moved = 1;
}