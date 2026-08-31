#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "light" : 3, "forest" : 1,
                    "night light" : 2 ]));
   set_short("Northeast corner of a garden");
   set_day_long("Sunlight shines brightly on the northeastern section "
     "of the garden. Small bushes and flowers line the stepping "
     "stones, which lead south and west. A thin wooden picket fence "
     "lines the limits of the garden. The northern Lodian tower rests "
     "southwest of this corner of the garden.");
   set_night_long("The bright moonlight beams down directly on the "
     "northeastern fence enclosed corner of this garden. The stars "
     "shine brightly, from which the flowers get a magical-looking "
     "glow. Bushes line the stepping stone path south and west.");
   set_items(([
     "fence" : "A picket fence encloses this part of the garden.",
     "bushes": "Bushes line the stepping stone path.",
     "path"  : "The stepping stone path was laid out with care.",
     "flowers":"An air of peace surrounds the flowers."
   ]));
   set_exits(([ "south": ROOMS"egarden2",
                "west" : ROOMS"ngarden"
   ]));
}

void reset() {
 ::reset();
   if (!present("faerie"))
     make(MOB"faerie");
}
