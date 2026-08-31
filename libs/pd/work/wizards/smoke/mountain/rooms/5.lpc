#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("Large bugs are scattered throughout the cavern. Some arctic ferns "
          "grow here despite the cold. Interesting rock formations line the "
          "walls. Loose rocks litter the floor, which has a sharp slant to it."
	  " A small hole in a rock on the western wall might spark some curiousity.");
 set_listen("default", "Wind whistles through the cavern.");
    set_items(([
({"bugs", "walls"}) : "Some nasty looking bugs climb the walls making some wierd"
	" noises.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temperatures."
	" The plant is all white and appears very brittle.",
({"hole"}) : "There is a small hole in the rock of the western wall. It looks large"
	" enough for something up to 2 meters to enter comfortably.",
({"rock", "rocks"}) : "The rock formations inside the cavern are amazing. They "
	"stretch up to the top of the mountain. It appears way to steep to climb."	
    ]));
    set_exits( ([ 
       "south" :  "/wizards/smoke/mountain/rooms/4",
       "west" :  "/wizards/smoke/mountain/rooms/6",
       "hole" :  "/wizards/smoke/mountain/rooms/den1"
    ]) );
}
