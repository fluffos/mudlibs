#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The ground here seems worn a bit more than higher in the "
          "mountain. Throughout the passageways, there are arcane "
	"symbols on the walls. There is a sharp turn here in the "
	"passage.");
    set_items(([
({"ground"}) : "The ground is more worn here than higher up. This part of"
	" the mountain must get more use.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"turn"}) : "The mountain walls make the path curved and cause sharp turns."
    ]));
    set_exits( ([ 
       "west" :  "/wizards/smoke/mountain/rooms/2_6",
       "south" :  "/wizards/smoke/mountain/rooms/2_8",
       "east" :  "/wizards/smoke/mountain/rooms/2_22"
    ]) );
}
void reset() {
    if(!present("lizard"))
        new("/wizards/smoke/mountain/monsters/lizard")->move(this_object());
        new("/wizards/smoke/mountain/monsters/lizard")->move(this_object());
}
