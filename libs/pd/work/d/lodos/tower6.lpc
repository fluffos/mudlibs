#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing up a twisted staircase");
   set_long("The twisted staircase leads higher up and down through the "
      "tower. A pool of blood stains the center of the stairs. The light "
      "here is dim, but is brighter right above here.");
   set_items(([ "staircase" : "It leads up, higher into the tower.",
      "blood" : "The blood leads up to the northern wall and stops.",
      "window" : "The room is dark due to the lack of a window.",
      "tower" : "It doesn't seem to be too much taller."
   ]));
   set_exits(([ "up" : ROOMS"tower7",
                "north" : ROOMS"secret1",
                "down" : ROOMS"tower5"]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_property("light", 1);
   set_invis_exits(({"north"}));
}

void reset() {
 ::reset();
   if (!present("soldier"))
     make(MOB"soldier2");
}
