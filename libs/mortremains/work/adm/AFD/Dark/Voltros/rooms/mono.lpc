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
  set("light", 1);
  set("short", "End of the path.");
	set_outside("zone", "2");
  set("long", @ENDLONG
All that is here at the end of the path is a small monolith.
It is made of a black material, and it looks very heavy.
ENDLONG
   );
  set("item_desc", ([
  "path" : "The path has little footprints all over it.\n",
   "monolith" : "The monolith is small, compared to other buildings.
By looking at it, it would seem that it is very heavy.  But somthing
dosen't seem right.\n",
   ]) );
  set("exits", ([
    "east" : ROOMS(wroad2),
  ]) );
  ::create();

}
int search(string what)
{
        object helmet;
        if(what != "monolith") return 0;
        if(found)
        {
          write("You find nothing strange about the monolith.\n");
          return 1;
        }
        found = 1;
        write("After searching for a while, you find a key sitting on the monolith.\n");
        helmet = clone_object(OBJ(bkey));
        helmet->move(TP);

        return 1;
}
