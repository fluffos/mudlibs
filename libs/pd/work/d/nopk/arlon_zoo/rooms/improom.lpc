#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "hole in the wall");
    set("long", "You're in a small room at the far end of the house.  This looks like"+
      " would make a nice hiding place.");
    set_exits( ([ "out" : ROOMS"dragonhouse2" ]) );
}
void reset() {
    ::reset();
    if(!present("imp")) {
	new(MOB"imp")->move(this_object());
    }
}
