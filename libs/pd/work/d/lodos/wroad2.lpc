#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Heading west, towards the town gates");
   set_long("This road has been expensively paved in magenta colored "
       "bricks. The square is east down this road, and to the west are "
       "the town gates. Further down this road a temple can be seen.");
   set_items(([ "temple" : "It is to the east of here." ]));
   set_exits(([ "east" : ROOMS"wroad1",
                "west" : ROOMS"wroad3"]));
   set_properties(([ "light" : 2, "town" : 1 ]));
}
