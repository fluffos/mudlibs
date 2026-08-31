#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a large tower");
   set_long("The tower does not seem to be all that much taller. The "
      "stairway looks like it only leads a short bit higher. The stairs "
      "wind around the center of the tower, up and down. The lighting here "
      "is dim, because there is no window.");
   set_listen("default", "You hear a bottle fall to the floor and smash below.");
   set_listen("bottle", "SMASH! *cursing*");
   set_items(([ "staircase" : "It leads up, higher into the tower.",
      "window" : "The room is dark due to the lack of a window.",
      "tower" : "It doesn't seem to be too much taller."
   ]));
   set_exits(([ "up" : ROOMS"tower6",
                "down" : ROOMS"tower4"]));
   set_property("light", 1);
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
}

void reset() {
 ::reset();
   if (!present("soldier")) {
     make(MOB"soldier");
     make(MOB"soldier");
   }
}
