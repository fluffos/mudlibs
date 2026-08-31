#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("Shadows dance along the walls from an unknown light source "
          "a ways off to the east. Ice ferns sit atop some rocks around "
          "the cavern. There is a huge crack in the rocks in the ceiling.");
 set_listen("default", "A cold gust of wind sends a chill through you.");
    set_items(([
({"light", "east", "shadows"}) : "Far to the east, there is an unknown glow " 
	"that is causing shadows to flicker along the walls here.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temperatures."
	" The plant is all white and appears very brittle.",
({"rock", "rocks"}) : "The rock formations inside the cavern are amazing. They "
	"stretch up to the top of the mountain. It appears way to steep to climb.",
({"crack"}) : "There is a huge crack in the ceiling. It looks easy enough to climb "
	"out of because the rocks here act as steps leading up to the crack."	
    ]));
    set_exits( ([ 
       "up" :  "/wizards/smoke/mountain/rooms/8",
       "east" :  "/wizards/smoke/mountain/rooms/2_2"
    ]) );
}
