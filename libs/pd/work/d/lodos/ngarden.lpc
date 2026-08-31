#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "light" : 2, "forest" : 1,
                    "night light" : 1 ]));
   set_short("North of a tower, in a garden");
   set_day_long("The garden is connected to a dirt road leading north. "
     "This part of the garden has yet to be tended to. Weeds overrun "
     "the flower bed and trees. About a carpet of moss are stepping "
     "stones leading both east and west.");
   set_night_long("Night shadows and weeds strangle the flowers and "
     "trees. The white trees are an eerie grey in the dim lighting. "
     "The weed choked stepping stones lead both east and west. A dirt "
     "road heads to the north.");
   set_items(([
     "road" : "The dirt road heads north from this part of the garden.",
     "garden":"The garden is still being tended to here.",
     "weeds": "Weeds choke the living plants.",
     "moss" : "A carpet of moss surrounds the stepping stones."
   ]));
   set_exits(([ "west" : ROOMS"wgarden3",
                "north": ROOMS"npath1",
                "east" : ROOMS"egarden3"
   ]));
}

void reset() {
 ::reset();
   if (!present("gardener"))
     make(MOB"gardener");
}
