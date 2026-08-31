#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside a large tower");
    set_long("This small room is littered with old experiments gone "
      "bad.  A small doorway leads north back into the tower stairway.  The "
      "walls, ceiling, and floor are a pale grey in color.");
    set_smell("default", "This room smells like many different chemicals.");
    set_items(([ "stairway" : "It can be seen out the doorway.",
	({ "doorway", "door" }):"Just an open doorway with no actual door."]));
    set_exits(([ "north" : ROOMS"tower4"]));
    set_properties((["light" : 2, "town" : 1, "indoors" : 1,
	"building" : 1]));
}

void reset() {
    ::reset();
    if (!present("alchemist"))
	new(MOB"alchemist")->move(this_object());
    if (!present("customer"))
	new(MOB"customer")->move(this_object());
}

void init() {
    ::init();
    if (present("customer"))
	if (this_player()->query_name() != "alchemist")
	    present("customer", this_object())->force_me("pick "+this_player()->query_name());

}
