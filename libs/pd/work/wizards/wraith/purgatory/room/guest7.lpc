#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest7");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This is the central hallway of the Guest Quarters. Down this "
"%^ORANGE%^hallway, the more prominent families call this home for the "
"%^ORANGE%^duration of their stay. A walkway leads to the north and the "
"%^ORANGE%^south.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"guest8", 
              "south" : ROOMS"guest6"]) );

    set_items( ([

        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}

