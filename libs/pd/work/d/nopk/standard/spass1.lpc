#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set("short", "Eastern end of the Daroq Mountains Pass");
    set("long",
	"This small path leads west above the Daroq Mountain "
        "pass. This path leads west, towards a ledge, above "
        "the pass.");
    set_items(
	(["pass" : "A gloomy pass through the Daroq Mountains.",
	  "highway" : "The Great Western highway.  It leads into Tirun.",
	  "caves" : "Several cave openings dot the sides of the pass.",
          "openings" : "They are the openings to caves.",
	  "pass" : "From here, the pass heads down westward into "
	    "a mountain range and the Qajip Desert."]));
    set_exits(([ "northeast" : ROOMS"pass4",
                 "west" : ROOMS"spass2" ]));
}
