#include <std.h>
#include <sindarii.h>
inherit ROOM;



  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
    set_long("This is the end of a path, here it splits into four other"
             " paths. There are many trees and vines above."
             " On the ground there are old leaves and dirt. Off to the"
             " southeast the forest seems to get"
              " thicker. To the southwest it get's denser.");
    set_short("A forest");
    set_items((["trees": "There are old trees, and little sapplings, all "
                         "the trees have vines on them",
                "leaves": "Most of the leaves are rotting"]));
    set_exits((["north": ROOMS"rain_forest/puddle",
                "southeast": ROOMS"rain_forest/dirtse",
//                "southwest": ROOMS"rain_forest/dirtsw", *error*
                "east": ROOMS"rain_forest/dirteast",
                "west": ROOMS"rain_forest/dirtwest" ]) );
    
}
