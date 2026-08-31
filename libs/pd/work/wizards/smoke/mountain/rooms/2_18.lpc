#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The walls inside the mountain twist and turn, making the "
          "path harder to follow. Rocks and dirt litter the ground. "
	"A shadow covers the east wall, making it hard to see anything."
	" The walls are cold and gray and are decorated with primitave "
	"looking symbols. There is a large crack in the ground that "
	"could be entered.  ");
    set_items(([
({"ground", "rocks", "dirt"}) : "The ground is littered with dirt and "
	"rocks.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean. ",
({"shadow"}) : "The shadow to the east are extremely thick.",
({"crack"}) : "The big crack in the ground is big enough to climb down.",
({"hall"}) : "The hall twists and turns throughout the inside of the "
	"mountain."
    ]));
    set_exits( ([ 
       "east" :  "/wizards/smoke/mountain/rooms/dcave",
       "northeast" :  "/wizards/smoke/mountain/rooms/2_17",
       "southeast" :  "/wizards/smoke/mountain/rooms/2_19",
       "down" :  "/wizards/smoke/mountain/rooms/3_1"
    ]) );
set_invis_exits(({"east"}));

}
