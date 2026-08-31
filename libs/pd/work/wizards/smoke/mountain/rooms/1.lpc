#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The snow on the ground starts to go away here on the "
          "way down the mountain. The slope slants downward in a "
          "spiral-shaped direction. ");
 set_listen("default", "A cold gust of wind sends a chill through you.");
    set_items(([
({"slope", "ground"}) : "The slope here goes down to the south or up to the west." 
	".",
    ]));
    set_exits( ([ 
       "west" :  "/wizards/smoke/mountain/rooms/ent",
       "south" :  "/wizards/smoke/mountain/rooms/2"
    ]) );
}
