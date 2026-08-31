#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Heading west, towards the town gates");
   set_long("This road, leading from the town gates to the central "
       "square is one of the most often-travled roads in Lodos. In "
       "addition to being the most often-travled road in Lodos, this "
       "path has been paved in expesive magenta tiles.");
   set_items(([ "temple" : "It is to the east of here." ]));
   set_exits(([ "east" : ROOMS"square",
                "south": ROOMS"weaponry",
                "west" : ROOMS"wroad2"]));
   set_properties(([ "light" : 2, "town" : 1 ]));
}
