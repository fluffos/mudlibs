#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The cavern comes to an abrupt end here. The inner walls of the mountain"
          " tower every way except from the northwest. There is a crack in the gr"
          "ound that leads down to another level. Some wild ice ferns line the "
	  "walls.");
    set_items(([
({"rocks", "walls"}) : "The walls are made up of some pretty cool rock formations."
	" The walls surround you in every direction except for the way you came.",
({"ground", "crack"}) : "There is a large crack in the ground that leads down to"
	" another level of the mountain.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temperatures."
	" The plant is all white and appears very brittle.",
    ]));
    set_exits( ([ 
       "northwest" :  "/wizards/smoke/mountain/rooms/7",
       "down" :  "/wizards/smoke/mountain/rooms/2_1"
    ]) );
}
