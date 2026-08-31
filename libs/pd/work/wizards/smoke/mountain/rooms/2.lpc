#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The snow on the ground starts to go away here on the "
          "way down the mountain. The slope slants downward in a "
          "spiral-shaped direction. It is freezing way up here. ");
 set_listen("default", "A cold gust of wind sends a chill through you.");
    set_items(([
({"slope", "ground"}) : "The slope here goes down to the southwest or up to the west." 
	".",
    ]));
    set_exits( ([ 
       "north" :  "/wizards/smoke/mountain/rooms/1",
       "southwest" :  "/wizards/smoke/mountain/rooms/3"
    ]) );
}
void reset() {
    if(!present("lizard"))
        new("/wizards/smoke/mountain/monsters/lizard")->move(this_object());
        new("/wizards/smoke/mountain/monsters/lizard")->move(this_object());
        new("/wizards/smoke/mountain/monsters/lizard2")->move(this_object());
}
