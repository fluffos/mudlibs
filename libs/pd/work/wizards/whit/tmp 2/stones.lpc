//  Whit

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Circle of Stones");
    set_short("a room with three stones in it");
    set_long("The air is cool and breezey here.  Three "
      "stones stand in the middle of the small clearing.  Each "
      "stone has a different color.  The stones colors consist of "
      "green, blue,  and yellow.  In the center of the circle of "
      "stones contain a pedistal.");
    set_items((["pedistal":"It looks as if something can be "
	"set on it.",
	({"stone", "stones"}):"The encircle the pedistal.  There are "
	"three colors of stone.  The colors consist of green, blue, "
	"and yellow.",
	"green stone":"The stone shimmers with power.",
	"yellow stone":"Much energy flows from this stone.",
	"blue stone":"A strange feeling comes over you when you look "
	"at this stone.",
      ]));
    set_exits(([
	"north":"/d/citrin/rooms/57",
      ]));
}

int is_event_area() { return 1; }

