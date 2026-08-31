#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Second story of the center tower");
   set_long("This is the second story of the central tower of the "
     "temple. The white and grey onyx walls and stairs continue upwards as "
     "well as down. Below, a large wooden circle can be seen and the "
     "temple's large bell can be seen up. This is but the second story of "
     "the largest tower in the temple. The room is mystically lit by some "
     "holy power.");
   set_items(([
     "power" : "A mystical holy force lights the room day and night.",
     "tower" : "This is the central bell tower of the temple.",
     "circle": "The only visible wooden part of the temple.",
     "bell"  : "Huge, golden and copper, it hangs from the top of the bell "
               "tower.",
   ({"walls","stairs"}) : "The walls and stairs are white and grey onyx."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
     "down" : ROOMS"l1m5",
     "up"   : ROOMS"l3m5"
   ]));
}


