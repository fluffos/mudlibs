#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The walls inside the mountain twist and turn, making the "
          "path harder to follow. Rocks and dirt litter the ground. "
	"The walls are cold and gray and are decorated with primitave "
	"looking symbols. Ice ferns grow randomly throughout the hall.");
    set_items(([
({"ground", "rocks", "dirt"}) : "The ground is littered with dirt and "
	"rocks.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temp"
	"eratures. The plant is all white and appears very brittle.",
({"hall"}) : "The hall twists and turns throughout the inside of the "
	"mountain."
    ]));
    set_exits( ([ 
       "southwest" :  "/wizards/smoke/mountain/rooms/2_24",
       "east" :  "/wizards/smoke/mountain/rooms/2_26"
    ]) );
}
void reset() {
    if(!present("ogre"))
        new("/wizards/smoke/mountain/monsters/ohunteress")->move(this_object());
        new("/wizards/smoke/mountain/monsters/ohunteress")->move(this_object());
        new("/wizards/smoke/mountain/monsters/oshaman")->move(this_object());
}
