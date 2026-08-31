#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("West of the temple entrance");
   set_day_long("This room is just west of the temple's entrance. Along the "
     "southern wall are stained glass windows depicting different religious "
     "scenes. Many varying colored beams of light shine through the stained "
     "glass windows into this grey and white onyx-walled room. Southwest of "
     "here a passage leads to some sort of a turret.");
   set_night_long("Stained glass windows line the entire southern wall, but "
     "aside from the moonlight, dimly shining into this grey and white onyx "
     "walled room, it is too dark to make out what the windows depict. This "
     "room is just to the west of the temple's entrance. A passage leads to "
     "the southwest, and another north.");
   set_items(([
     "passage" : "The passage leads southwest to a turret.",
     "turret"  : "It reaches just above the height of the temple.",
     "walls"   : "Made of both grey and white onyx, the walls go nicely with the "
                 "white tiled floors.",
     "floor"   : "Covered completely with white tile.",
     "windows" : "Stained glass windows depict angels and other holy scenes."
   ]));
   set_exits(([ "north"     : ROOMS"l1m4",
                "east"      : ROOMS"l1m8",
                "southwest" : ROOMS"l1sw2"
   ]));
}

