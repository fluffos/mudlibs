#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest33");
     set_short("The Guest Quarters");
     set_long("%^CYAN%^This room looks battered and beaten. All of the walls have "
"%^CYAN%^been ripped from where they once stood, and the ceiling has "
"%^CYAN%^collapsed onto the floor. The remains of a bed and other "
"%^CYAN%^various type of furniture have been crushed under the rubble.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( ([
              "southwest" : ROOMS"guest8"]) );

    set_items( ([
        "floor" : "Rubble and wod shingles make walking on this floor a hazardous job.",
        "ceiling" : "Bits and peices of the ceiling litter the floor. The sky is now the limit to this room.",
        "wall" : "Only small portions of the wall have been left over.",
        "bed" : "The bed has been ripped to shreds by falling debris.",
        "furniture" : "Its hard to tell what was once in this room now."
      ]) );


}

