#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Heading west, towards the town gates");
    set_long("The tall, silver gates stand to the west of this part "
      "of the road. The road glimmers in the frosty mountain air. "
      "Several trees line the side of the road. Off to the west, "
      "Lodos' most recognizable structure stands tall; the temple.");
    set_items(([ "temple" : "It is to the east of here." ]));
    set_exits(([ "east" : ROOMS"wroad3",
      ]));
    set_properties(([ "light" : 2, "town" : 1 ]));
}
