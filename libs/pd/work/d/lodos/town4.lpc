#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
 ::create();
   set_long("The old, worn out road leads northwards through town and "
      "south into the town square. A rather small shop is to the east "
      "of here.");
   set_short("Heading north of Lodos Town Square");
   set_properties(([ "town" : 1, "light" : 1 ]));
   set_exits(([
      "north" : ROOMS"ntown5",
      "south" : ROOMS"square",
      "east" : ROOMS"armoury"
   ]));
}

void reset() {
 ::reset();
   if (!present("citizen"))
     make(MOB"citizen");
}
