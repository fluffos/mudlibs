#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
   set_short("hut1");
   set_long("A small area near the edge of the village. "
            "There is a large guard hut right near here. There is "
            "also a large wooden fence at the edge of the fortress.");
   set_items((["hut" : "There is a large hut made out of large logs "
                       "and sticks. It seems that it is still very "
                       "sturdy.",
               "fence" : "The fence is many sharp large poles "
                         "which are faced away from the village "
                         "to keep out any unwanted intruders."]));
   set_exits((["east" : ROOMS"village1",
               "enter" : ROOMS"ghut1"]));

}
