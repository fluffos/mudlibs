#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The ground here seems worn a bit more than higher in the "
          "mountain. Throughout the passageways, there are arcane "
	"symbols on the walls. The halls of the cavern are long and "
	"mostly plain.");
    set_items(([
({"ground"}) : "The ground is more worn here than higher up. This part of"
	" the mountain must get more use.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"halls"}) : "The halls are long and don't contain much stuff."
    ]));
    set_exits( ([ 
       "north" :  "/wizards/smoke/mountain/rooms/2_7",
       "southeast" :  "/wizards/smoke/mountain/rooms/2_9"
    ]) );
}
void reset() {
    if(!present("lion"))
        new("/wizards/smoke/mountain/monsters/mlion")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mgoat")->move(this_object());
}
