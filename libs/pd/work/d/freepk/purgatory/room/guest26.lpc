#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest");
     set_short("The Guest Quarters");
     set_long("%^GREEN%^These quarters look to have been ransaked by professionals, "
"%^GREEN%^everthing is either flipped over or turned inside out. The "
"%^GREEN%^pictures and mirrors have been smashed to pieces and strewn "
"%^GREEN%^across the room.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["out" : ROOMS"guest4" ]) );

    set_items( ([
        "pictures" : "Broken frames of the paintings lay far away from where they were once hung.",
        "mirrors" : "The mirrors have been smashed to bits, making is difficult for any barefooted person to walk."
      ]) );


}

