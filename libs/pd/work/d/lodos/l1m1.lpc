#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("A corner of the temple");
   set_day_long("This room is the northwest corner of the main part of this "
     "temple. A doorway has been carved into the white onyx walls heading south. "
     "Yet another doorway branches from this room to the east. A tower, more of "
     "a turret, is northwest. The turret reaches just above the roof of the "
     "temple.");
   set_night_long("The night completely transforms this holy temple. What was once "
     "is now dim, what was white is nearly black. What was once magestic and "
     "awesome is now questionable at best. Dim candle light is the only source "
     "of light. Two doorways have been carved into the onyx walls; one leading "
     "east and the other south. A passage is northwest, connecting the main "
     "temple to the northwest turret.");
   set_items(([
     "turret"   : "The turret is just barely taller than the temple.",
     "doorways" : "Two doorways have been cut into the onyx walls.",
     "corner"   : "Northern corner of the temple, a turret is northwest."
   ]));
   set_exits(([ "east"      : ROOMS"l1m2",
                "northwest" : ROOMS"l1nw4",
                "south"     : ROOMS"l1m4"
   ]));
}

void reset() {
 ::reset();
/*   if (!present("healer"))
     make(MOB"healer");*/
}

