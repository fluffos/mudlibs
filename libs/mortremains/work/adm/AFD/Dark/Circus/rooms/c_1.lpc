

#include "../defs.h"
int found;
inherit ROOM;   
void init()
{
add_action("search", "search");
}
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In an Animal's cage.");
  
set("long", @ENDLONG
The odor of the cage is horrendous.  You aren't sure if it is feces, or
the decaying flesh of some unfortunate creature.  A thick layer of
hay makes walking quite difficult.
ENDLONG
);

  set("item_desc", ([
    "hay" : "The hay is obviiously used as a bed for a very large creature.\n",
 ]) );
  set("smell", ([ "default" : "Your stomach rolls from the intense stench that
pervades the entire cage.\n",
]) );
  set("objects", ([ MON(huge) : 1, ]) );
  set("exits", ([
   "out" : ROOMS(cage1),
]) );
  ::create();  
}
int search(string what)
{
        object ring;
        if(what != "hay" && what != "floor") return 0;
        if(present("badger", TO)){ write("The badger growls angrily at you.\n"); return 1; }
        if(found)
        {
          write("You find nothing hidden in the hay.\n");
          return 1;
        }
        found = 1;
        write("You find a ring in the hay!\n");
        ring = clone_object(OBJ(ring));
        ring->move(TP);

        return 1;
}