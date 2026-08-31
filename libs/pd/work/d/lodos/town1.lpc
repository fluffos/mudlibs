#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_properties(([ "town" : 1 ]));
   set_short("Heading east of the Lodos Town Square");
   set_long("The old dirt path leads east and west right "
            "through town square. The Lodos armoury is to "
            "the north and southeast of here is a large temple.");
   set_exits(([ "west" : ROOMS"square",
                "north" : ROOMS"armoury",
                "east" : ROOMS"town2"]));
}
