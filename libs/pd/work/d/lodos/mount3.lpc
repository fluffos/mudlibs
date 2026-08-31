#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Traveling on a mountain road");
   set_long("Just to the south, along this mountain road, a pass "
      "can be seen. Several small, although mostly dead, trees line "
      "the sides of the road. There is no dirt along the road, only "
      "rock.");
   set_exits(([ "north" : ROOMS"mount2",
                "south" : ROOMS"mount4"]));
   set_properties(([ "light" : 2 ]));
   set_property("mountain",1);
}

void reset() {
 ::reset();
// if (!present("llama"))
//      make(MOB"llama");
}
