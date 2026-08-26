#include "../defs.h"
int found;
inherit ROOM;
void init()
{
add_action("search", "search");
}
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 0);
  set("short", "Burial place.");

set("long", @ENDLONG
In the center of this circular room, you see a nest of some sort.
Cubbyholes are cut out of the walls, and coffins have been placed
in them.  There is a thick layer of dust over everything;  The
smell of potpourri is thick.

ENDLONG
);

  set("item_desc", ([
    "dust" : "The dust is untouched, letting you know that the room has been unentere
d for years.\n",
    "coffins" : "All of the coffins look like they have never bee
n touched.\n",
				"nest" : "Bones and other miscellanenous objects litter the nest.\n",
 ]) );

  set("objects", ([ MON(scorpion) : 1, ]) );
  set("exits", ([
   "west" : ROOMS(ntemple1),
]) );
  ::create();
}
int search(string what)
{
        object helmet;
        if(what != "nest") return 0;
        if(found)
        {
          write("You find nothing but refuse strewn about the nest.\n");
          return 1;
        }
        found = 1;
        write("After searching for a while, you find a helmet that might be useful.\n");
        helmet = clone_object(ARMOR(ohelmet));
        helmet->move(TP);

        return 1;
}