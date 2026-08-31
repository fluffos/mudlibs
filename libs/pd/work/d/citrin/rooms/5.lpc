//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
     ::create();
     set_name("a forest");
     set_short("a forest");
     set_long("Tall trees appear on all sides of the path.  The "
		"trees stretch very far into the sky.  The heavy "
		"amount of leaves in the canopy keeps out much light "
		"from reaching the ground.  Small slivers of light "
		"come from the entrance to the forest to the west.");
     set_items(([
		({"tall tree","tree","trees","tall trees"}):"They stretch for into "
							    "the sky blocking out "
							    "most of the light.",
]));
     set_exits(([
		"west":ROOMS"4",
		"east":ROOMS"6",
		"south":ROOMS"7",
]));
     set_properties((["light":1,"night light":1,"forest":1,]));
}

