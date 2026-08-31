#include <std.h>
#include <rain.h>
inherit ROOM;
create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Standing in a small hut");
   set_long("Inside this house there are only a few things. "
            "Off in the corner is a bed. There is a Bow and "
            "quiver of arrows in the other corner. There are"
            " also some toys scattered on the ground.");
   set_items((["bed" : "This bed is not that big, only 2 people "
               "could fit on it.",
               "bow" : "This used to be a sturdy bow which could be used "
               "for war and hunting.  It is old and useless, now",
               "toys" : "There are a few toys just sitting on the "
               "ground.",
               "quiver" : "This quiver has a few broken arrows sitting in it"]));
   set_exits((["out" : ROOMS"home5"]));
}
