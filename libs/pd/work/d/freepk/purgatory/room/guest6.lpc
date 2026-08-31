#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest6");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This is the central hallway of the Guest Quarters. Down this "
"%^ORANGE%^hallway, the more prominent families call this home for the "
"%^ORANGE%^duration of their stay. A beautiful porch is built into this "
"%^ORANGE%^section of the walkway for weary people to rest and look out "
"%^ORANGE%^over the land.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"guest7", 
              "south" : ROOMS"guest5"]) );

    set_items( ([
        "land" : "Rolling hills pocketed with farms and grasslands fill the view from this side of the castle.",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}
