#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("A secret passage");
     set_short("A secret passage");
     set_long("The %^RESET%^%^GREEN%^moss%^RESET%^ looks to have thinned out around "
"the northern part of the walls. The floors seem less slippery. "
"Moving through the passage, there seems to be a light coming from the northeast.");
     set_properties(([
        "light"       : 2,
        "night light" : 0,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["south" : ROOMS"cyard70", 
              "northeast" : ROOMS"yard1"]) );


    set_items( ([
        "moss"  : "A %^RESET%^%^GREEN%^green%^RESET%^ lichen like moss has grown on the walls.",
        "wall" : "The walls have been covered with a %^RESET%^%^GREEN%^green moss%^RESET%^ that looks pretty slimy.",
        "floor" : "A %^BOLD%^%^BLACK%^darker %^RESET%^%^GREEN%^moss%^RESET%^ has sprouted up on the floor in absence of regular travelers.",
      ]) );

}
