#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "light" : 2, "forest" : 1,
                    "night light" : 2 ]));
   set_short("East of a tower, in a garden surrounding it");
   set_day_long("The stepping stone path continues north and south "
     "through the garden surrounding the northern tower. Sunshine "
     "beats down brightly on this section of the garden. Bright green "
     "grass grows in a small meadow near the picket fence to the east.");
   set_night_long("As the night winds blow across this part of the "
     "garden, the small meadow near the eastern fence waves like a "
     "midnight blue ocean. The moonlight illuminates the area rather "
     "well, because the tower's shadow is cast west. A picket fence "
     "surrounds the eastern part of the garden.");
   set_items(([
     "fence" : "It surrounds the whole eastern side of the garden.",
     "grass" : "The grass grows along the northern bank of a small "
               "spring.",
     "light" : "The eastern garden is well lit, away from the tower's "
               "shadow."
   ]));
   set_exits(([ "north" : ROOMS"egarden3",
                "south" : ROOMS"egarden1"
   ]));
}

void reset() {
 ::reset();
   if (!present("plant"))
     make(MOB"flytrap");
}
