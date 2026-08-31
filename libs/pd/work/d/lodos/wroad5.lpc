#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("East of the Lodos town gates");
   set_long("The maroon brick road ends just to the west, before the "
      "tall, silver western gates. This road leads out of the town, and "
      "towards the far off town of Tirun.");
   set_items(([ "gates" : "The tall silver gates stand high above you"]));
   set_exits(([ "east" : ROOMS"wroad4",
                "west" : ROOMS"gates"]));
   set_properties(([ "light" : 2, "town" : 1 ]));
}
