#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
                "no teleport" : 1]) );
   set_short("Inside a mage tower");
   set_long(
            "Dark stone walls stretch high into the tower. A "
            "spiraling staircase winds up several flights. A wooden "
            "handrail twists with the staircase. High atop the tower "
            "a glowing blue light can be seen.");
   set_items(([
            "staircase" : "A spiraling staircase leads up to the top "
                        "of the tower.",
            "walls" : "%^BOLD%^%^BLACK%^Dark stone walls stretch high "
		 "into the tower.",
            "handrail" : "The wooden handrail twists and turns with "
                 "the staircase. ",
            "light" : "A %^BOLD%^%^CYAN%^glowing blue light%^RESET%^ comes "
		 "from the top of the tower."
   ]));
   set_smell("default", "It almost smells like burnt hair.");
   set_listen("default", "The crackling of energy is strong here.");
   set_exits( ([ 
        "northwest" :  ROOMS "tower5_3",
        "southwest" :  ROOMS "tower5_1"]));
}
