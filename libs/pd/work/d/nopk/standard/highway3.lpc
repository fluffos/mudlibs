#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set("short", "The Western Highway in the shadows of the Daroq Mountains");
    set("long",
	"The Daroq Mountains tower above you to the west, blocking "
	"out the sky so much that an eerie twilight covers the land. "
        "There is a small overgrown path to the south heading towards "
        "some rather ominous-looking peaks in the distance. "
	"The Great Western Highway, which provides a route of travel "
	"east, ends just west of here in a mountain pass.");
    set_items(
	(["peaks" : "The peaks you see are the twin peaks of the "
	  "Destiny Mountains.",
	  "mountains" : "A huge mountain range west of the ",
	  "mountain" : "Kateihl Mountain, a former stronghold of goblins.",
	  "highway" : "The Great Western Highway ends here at a "
	    "mountain pass.",
	  "forest" : "A very dark, uninviting forest."]) );
    set_exits( 
	      (["west" : ROOMS "pass1",
                "south" : ROOMS "cult/ent",
		"east" : ROOMS "highway2"])  );
}
