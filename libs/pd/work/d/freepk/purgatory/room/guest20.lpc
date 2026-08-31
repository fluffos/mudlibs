#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest20");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This is the western wing of the Guest Quarters. The servants "
"%^ORANGE%^of the Lords and Ladies rest in these rooms. Inelegant "
"%^ORANGE%^design, and shoddy craftmanship show this to be a lesser "
"%^ORANGE%^hallway. A small walkway leads to the north and south. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"guest21", 
              "south" : ROOMS"guest19"]) );

    set_items( ([
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}

