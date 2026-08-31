#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
    set_short("End of east passage");
    set_long("The end of a short corridor. "
      "It has some paintings on the wall, and carpet on "
      "the ground. There is a couch sitting against one "
      "of the walls.");
    set_items((["paintings" : "These are paintings of landscapes",
	"carpet" : "A beautiful embroidered carpet.",
	"couch" : "A large plush couch"]));
    set_exits((["west" : ROOMS "palace3"]));
}

void reset() {
    ::reset();
    if(!present("council"))
	new(MOB"council")->move(this_object());
}
