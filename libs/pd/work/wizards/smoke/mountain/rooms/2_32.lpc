#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The walls inside the mountain twist and turn, making the "
          "path harder to follow. Rocks and dirt litter the ground. "
	"The walls are rough and jagged here and are covered with primi"
	"tave looking symbols. Ice ferns grow randomly throughout the hall.");
    set_items(([
({"ground", "rocks", "dirt"}) : "The ground is littered with dirt and "
	"rocks.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temp"
	"eratures. The plant is all white and appears very brittle.",
({"walls", "wall"}) : "The walls look like they've been mined here."
	" They look rough and jagged and are full of indentations.",
({"hall"}) : "The hall twists and turns throughout the inside of the "
	"mountain."
    ]));
    set_exits( ([ 
       "east" :  "/wizards/smoke/mountain/rooms/2_31",
       "south" :  "/wizards/smoke/mountain/rooms/2_33",
       "west" :  "/wizards/smoke/mountain/rooms/willysrm"
    ]) );
set_invis_exits(({"west"}));
}
void reset() {
    if(!present("ogre"))
        new("/wizards/smoke/mountain/monsters/owarrior")->move(this_object());
        new("/wizards/smoke/mountain/monsters/oshaman")->move(this_object());
}
