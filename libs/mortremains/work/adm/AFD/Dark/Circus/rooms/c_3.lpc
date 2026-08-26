
#include "../defs.h"
inherit ROOM;   
void init()
{
add_action("search", "search");
}
int found;
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In an Animal's cage.");
  
set("long", @ENDLONG
 Rotting corpses line the walls and the floor of this disugusting place.
You wretch at the sight of maggots feasting on the eyes of a dead halfling.
Whatever animal lives in this cage must love to consume humanoid flesh.
ENDLONG
);

  set("item_desc", ([
    "corpses" : "Tearing wounds can be seen on the corpses.\n",
    "maggots" : "The white insects could feast on these bodies their entire lives 
and have plenty left over for the generations to come .\n",
 ]) );
  set("smell", ([ "default" : "Your stomach rolls from the intense stench that
pervades the entire cage.\n",
]) );
  set("objects", ([ MON(ugoat) : 3, ]) );
  set("exits", ([
   "out" : ROOMS(cage3),
]) );
  ::create();  
}
int search(string what)
{
        object scale;
        if(what != "corpses" && what != "floor" && "bodies" && "corpse") return 0;
        if(present("goat", TO)){ write("The goat doesn't let you near the floor.\n"); return 1; }
        if(found)
        {
          write("You find nothing hidden in the hay.\n");
          return 1;
        }
        found = 1;
        write("You find some armor you can salvage off one of the corpses!\n");
        scale = clone_object(ARMOR(scale));
        scale->move(TP);

        return 1;
}