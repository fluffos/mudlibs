#include <std.h>
#include <purgatory.h>

inherit ROOM;


void create() {
    ::create();
     set_name("guest25");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^The hallway in this part of the Guest Quarters looks like a "
"%^ORANGE%^battle was just finished. Bloodstains and large amounts of "
"%^ORANGE%^gore are spread around the hallway. A shoddily build door "
"%^ORANGE%^hangs off its hinges to the east. The walkway leads to the "
"%^ORANGE%^south.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["south" : ROOMS"guest24", 
              "enter" : ROOMS"guest42"]) );

    set_items( ([
        "walls" : "The entrails of a servant have dried to the wall",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}
