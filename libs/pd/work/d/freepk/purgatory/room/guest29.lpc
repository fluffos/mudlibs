#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest29");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This room has been abandoned because half of the east side "
"%^ORANGE%^has been ripped off. Clothes scatter the floor and fly out "
"%^ORANGE%^into the open air on random gusts of wind. The senic view "
"%^ORANGE%^once held in the window can now be seen through the rubble "
"%^ORANGE%^that used to be the east wall.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( ([ 
              "out" : ROOMS"guest3"]) );

    set_items( ([
        
        "rubble" : "Broken stones and dirt have been piled up by the crashes.",
        "wall" : "Cracks have formed along the walls from the recent loss.",
        "view" : "The forest can be seen out of what was once the east wall."
      ]) );


}

