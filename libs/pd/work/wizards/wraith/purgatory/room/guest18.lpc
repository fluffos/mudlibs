#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest18");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This is a small hallway that connects all three of the main "
"%^ORANGE%^hallways. A few small chairs stand against a wall for people "
"%^ORANGE%^to take a break from the hustle and bustle of the guest "
"%^ORANGE%^quarters. A small walkway leads to the east and southwest.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"guest2", 
              "southwest" : ROOMS"guest19"]) );

    set_items( ([
        "chair" : "Unelegant design and a thought for comfort show in the craftmanship of this chair.",
        "chairs" : "These chairs are not very elegant, but they look to provide some confort when sat in.",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway in the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}

