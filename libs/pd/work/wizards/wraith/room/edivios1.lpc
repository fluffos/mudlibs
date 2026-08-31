#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "East Divios south of the monastary");
    set("long",
      "Divios on the east side of the town is a simple dirt road "
      "leading towards Arulo Juncture at the centre of Sindarii west and out "
      "into the western outskirst west.  The village monastary is on "
      "the north side of the road.");
    set_exits(([
                "north" : ROOMS"monastery",
                "east" : ROOMS"edivios2",
                "west" : ROOMS"square",
                "south" : ROOMS "oil_shop"]));
    set_items(
	      (["road" : "Boc La Road, the main east-west path "
		  "through Praxis.", 
		"monastary" : "The monks of Carnage make their home there.",
		"square" : "Town Square, the center point of "
		  "Sindariian life."]) );
}

