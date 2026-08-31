#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("A sharp angled wall creates a fork in the path. The "
          "ground here is more worn than higher up in the mountain, "
	"meaning there is more traffic here. The hall stretches off "
	"into the darkness.");
    set_items(([
({"ground"}) : "The ground is more worn here than higher up. This part of"
	" the mountain must get more use.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"darkness"}) : "It is way too dark to see what's hiding in the shadows.",
({"hall"}) : "The hall twists and turns throughout the inside of the "
	"mountain."
    ]));
    set_exits( ([ 
       "north" :  "/wizards/smoke/mountain/rooms/2_9",
       "southwest" :  "/wizards/smoke/mountain/rooms/2_11",
       "east" :  "/wizards/smoke/mountain/rooms/2_43"
    ]) );
}
