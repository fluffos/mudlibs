#include "../defs.h"
inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Waxer");

  set("light", 1);


  set("short", "in a cramped cavern.");

set("long", @ENDLONG
The heat here is very intense.  Steam rises from a large,
black pool of water.  The ground beside the pool is mostly
gravel and larger rocks.  The steam rises from the pool
through a hole above you.
ENDLONG
   );

  set("item_desc", ([
    "pool" : "Its appears quite deep, for you cannot see the bottom, perhaps you
should [jump into] it.\n",
    "ground" : "The ground here is covered with little pebbles and some larger rocks.\n",
    "steam" : "The steam is very hot to the touch, and it's touching
nearly every part of you.\n",
     "hole" : "The hole appears to be the only way out.\n",
     "gravel" : "The ground here is covered with little pebbles and some larger rocks.\n",
]) );
  set("smell", ([
    "default" : "You smell only the water in the air.\n",
    "pool"  : "You would have to jump into it to get a closer look.\n",
]) );
  set("exits", ([
   "up" : ROOMS(tube8),
                ]) );
  set("objects", ([ MON(g_frog) : 4, ]));
::create();
}
void init(){
add_action("jump","jump");
add_action("jump", "dive");
}

int jump(string str) {
  if (!str) return 0;
  if((int)TO->query("monst"))
  {
   write("You have the feeling it wouldn't be wise to do that.\n"); return 1;
  }
  if (str != "into pool" && str != "into water" && str !="in"){

// instead of just returning 0, because of the dive and jump emotes.

    write("What?\n");
    return 1;
  }
  write("A scaled arm reaches up from the water nearly catching you\nin mid-air.  After tasting the wrath of its claws,\nyou decide not to do that again\n");
  TP->receive_damage(random(20));
TO->set("monst", 1);
return 1;

}
