// seeker

#include <std.h>
#include <rain.h>
inherit ROOM;

void create()
{
    ::create();
    set_short("in the forest");
    set_long("The forest is very humid. The ground is squishy and "
      "leaves cover the ground. Trees tower above blocking "
      "out the sky. Mildew and mold covers the side of the trees. "
      "The path stops abruptly here.");

    set_items( 
      ([ "vines" : "The vines go from tree to tree.",
	"trees" : "The trees tower over you.",
	"ground": "The grounds full of leaves and is soggy." ]) );
    set_property("light", 3);
    set_property("forest", 1);
    set_property("night light", 2);

    set_smell("default", "The humid air stifils your senses.");
    set_listen("default", "You hear animals squeeking.");

    set_exits( ([ "southwest" : ROOMS"path5",
	"south" : ROOMS"dirt" ]) );
}

void reset() {
    ::reset();
    if (!present("ant")) {
	new(MOB"ant")->move(this_object());
	new(MOB"ant")->move(this_object());
    }
}
