#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
		"no teleport" : 1]) );
   set_short("Caelum Palatium");
   set_long(
            "%^YELLOW%^This is the enterance to Caelum Palatium. A long "
            "hallway stretches east, while two magnificent iron doors "
            "least out to the sky. The walls and ceiling are made of solid "
            "gold and the floor is made of marble.");
   set_items(([
            "doors" : "Two iron doors are open, leading from the palace back "
			"to the sky.",
	     ({"walls", "ceiling"}) : "%^YELLOW%^The palace walls and ceiling are "
		"made of solid, pure gold!%^RESET%^",
            "floor" : "The floor is made of the most beautiful marble ever created.",
   ]));
   set_smell("default", "Insence burn throughout the palace.");
   set_listen("default", "Any footsteps can be heard throughout the entire palace.");
   set_exits( ([ 
	"east" :  ROOMS "p_002",
        "out" :  ROOMS "s_001"]));
}
