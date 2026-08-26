#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);

  set("short", "at an odd corner.");
  
set("long", @ENDLONG
The tunnel is quite odd here.  The walls to the south
the walls have been carved smoothe, but the other surrounding
walls are quite rough and unmined.  There is a small room
in the cave to the west.  There is a hole in the ground.
ENDLONG
   );

  set("item_desc", ([
    "walls" : "It appears as though that the inhabitants of this place haven't mined\nthisfar up the tunnel.\n",
    "wall" : "It appears as though that the inhabitants of this place haven't mined\nthisfar up the tunnel.\n",
    "niche" : "The stain looks to have been formed by a liquid of some sort.\n",
    "hole" : "It's a hole in the ground, steam seems to be rising from it.\n"
]) );
   set("search_desc", ([
     "wall" : "This wall is completely smooth.\n",
     "hole" : "You might be able to go \"down\" it....\n",
   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air, mixed with a thick\nsteamy smell.\n",
    "wall"  : "You smell the nothing except for rock.\n",
  ]) );
  set("listen", ([ "default" : "You hear a light clicking sounds to the west.\n", ]) );
 
  set("exits", ([
    "west" : ROOMS(cave9),
    "south" : ROOMS(cave7),
    "down" : ROOMS(tube.c),
  ]) );
  ::create();
  set("exit_suppress", ({ "down" }));
  set("pre_exit_func", ([ "down" : "foo" ]));
}
int foo(){
if((int)TP->query("size") > 8){
  write("You can't squeeze down into the hole.\n"); return 1;
}
write("You squeeze down the hole, getting some nicks and scratches.\n");
TP->receive_damage(random(5));
return 0;
}