// NS

#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
   set_long("Animals are everywhere. The lush green leaves "
           "sparkle in the faint sunlight. There is a large "
           "hole in the canopy here.  It would be possible to "
           "go down, but there seems to be no way to come back...");
set_items( 
          ([ "vines" : "The vines go from tree to tree.",
             "trees" : "The trees tower over you.",
             "hole": "The hole leads down to the ground below.",
             "monkeys" : "They seem to be moving quickly." ]) );
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");
set_exits( (["northwest" : ROOMS"rain_forest/canopy_s1",
              "down" : ROOMS"rain_forest/dirtsw"]) );
}
