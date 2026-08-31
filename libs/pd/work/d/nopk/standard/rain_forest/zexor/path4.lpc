#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
   ::create();
   set_short("In a forest");
   set_long("The Zexorion forest. The area is deathly silent. The vegitation has thinned.");
   set_items((["tree" : "A giant tree blocking the road to the south",
       "trees" : "Many different trees",
       ({"bushes", "leaves", "grass"}) : "Just foilage on the ground"]));
   set_exits((["northeast" : ROOMS"path3",
       "southeast" : ROOMS"path5"]));
}
