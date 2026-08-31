#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The hall twists and turns throughout the inside of the "
          "mountain. There are symbols drawn on the walls all over "
	"the place, but there is no way to determine what they read. "
	"");
    set_items(([
({"ground"}) : "The ground is more worn here than higher up. This part of"
	" the mountain must get more use.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"hall"}) : "The hall twists and turns throughout the inside of the "
	"mountain."
    ]));
    set_exits( ([ 
       "northwest" :  "/wizards/smoke/mountain/rooms/2_8",
       "south" :  "/wizards/smoke/mountain/rooms/2_10"
    ]) );
}
void reset() {
    if(!present("ogre"))
        new("/wizards/smoke/mountain/monsters/owarrior")->move(this_object());
        new("/wizards/smoke/mountain/monsters/owarrior")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mgoat")->move(this_object());
}
