#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "Monastary stairwell");
    set("long",
        "A spiraling flight of stairs leads up to the monastery "
        "attic and down to the cellar. The prayer area is west.");
    set_exits( 
	      (["west" : ROOMS"monastery",
		"up" : ROOMS"monk_join",
		"down" : ROOMS"immortal_hall"]) );
    set_items(
        (["stairs" : "They spiral up and down in this old monastery."]) );
    set_property("no castle", 1);
}


