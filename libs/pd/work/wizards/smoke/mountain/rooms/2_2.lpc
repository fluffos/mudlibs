#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("Shadows dance along the walls from an unknown light source "
          " off to the east. Ice ferns seem to grow more abundantly"
          " here along the walls of the cavern.");
 set_listen("default", "A cold gust of wind sends a chill through you.");
    set_items(([
({"light", "east", "shadows"}) : "Off to the east, there is an unknown glow " 
	"that is causing shadows to flicker along the walls here.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temperatures."
	" The plant is all white and appears very brittle. The ferns along the"
	" north wall look like they're growing over something.",
({"rock", "rocks"}) : "The rock formations inside the cavern are amazing. They "
	"stretch up to the top of the mountain. It appears way to steep to climb.",
({"north wall"}) : "There looks like there is a hole in the north wall hidden "
	"behind a patch of ferns that grow wild.",
({"hole"}) : "Behind the ferns along the north wall, there is a hole in the rock."
	" It looks big enough to squirm through."	
    ]));
    set_exits( ([ 
       "west" :  "/wizards/smoke/mountain/rooms/2_1",
       "hole" :  "/wizards/smoke/mountain/rooms/hole1",
       "east" :  "/wizards/smoke/mountain/rooms/2_3"
    ]) );
set_invis_exits(({"hole"}));
}
