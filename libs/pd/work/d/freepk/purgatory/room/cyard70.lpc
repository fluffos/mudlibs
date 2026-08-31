#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("A secret passage");
     set_short("A secret passage");
     set_long("This is a secret passage that leads to the courtyards. "
"The walls are covered in %^BOLD%^%^WHITE%^pale %^RESET%^%^GREEN%^moss%^RESET%^ and the "
"floor is slippery underfoot. It does not look like this passage has been used "
"in a long while.");
     set_properties(([
        "light"       : 2,
        "night light" : 0,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["south" : ROOMS"castle24", 
              "north" : ROOMS"cyard69"]) );


    set_items( ([
        "moss"  : "A %^RESET%^%^GREEN%^green%^RESET%^ lichen like moss has grown on the walls.",
        "wall" : "The walls have been covered with a %^RESET%^%^GREEN%^green moss%^RESET%^ that looks pretty slimy.",
        "floor" : "A %^BOLD%^%^BLACK%^darker %^RESET%^%^GREEN%^moss%^RESET%^ has sprouted up on the floor in absence of regular travelers.",
      ]) );

}
