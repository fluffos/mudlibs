#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
  ::create();
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("night light", 1);
    set_smell("default", "An unbelievable stench fills the "
		     "air from the west.");
    set_smell("dump", "It smells of all kinds of "
		     "nasty rotting things.");
    set("short", "The end of a nasty alley");
    set("long",
	"This nasty alley ends at the town dump to the west. "
	"There is a worn down building to the south and some "
	"other ruined areas north.");
    set_items(
	(["alley" : "It goes through the worst parts of Praxis.",
	  "dump" : "People take their trash there. Always "
	    "during daytime hours.",
	  "building" : "It looks like no one has paid it any "
	    "attention in eons.",
	  "ruins" : "Graffiti covers them."]) );
    set_exits( 
              ([ "east": ROOMS"alley1",
                "north": ROOMS"wall",
                "south": ROOMS"building",
                "west": ROOMS"dump" ]) );
}
