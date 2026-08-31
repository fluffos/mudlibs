#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest11");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This room looks like it has been halfway built. On closer "
"%^ORANGE%^inspection, it appears that the room has actually been torn "
"%^ORANGE%^down along with the rest of the hallway. The walkway heads "
"%^ORANGE%^off back to the south.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( ([ 
              "south" : ROOMS"guest10"]) );

    set_items( ([
        
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters. Broken and ripped up the stones only lead back south."
      ]) );


}

