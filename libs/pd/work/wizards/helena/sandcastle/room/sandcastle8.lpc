#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 2, "night light" : 2, "indoors" : 1, "no attack" : 1, "no bump" : 1, "no steal" : 1, "no magic" : 1]) );
set_short("West Upstairs");
set_long("This looks like it used to be a playroom. It is somehow clean in here, the walls smoothed out and stable. This looks like the kinda room you could just sit in for hours and be safe and worry free all day and night.");
set_items((["room" : "The room is nice and clean, although its made out of sand, and has a happy glow in it.", "walls" : "They are nice and smooth. You feel happy.", "floor" : "It is nice and solid, no cracks, and its all clean too.", "ceiling" : "It is above you...looks like someone drew doodles of clouds on the ceiling."]));
set_smell("default", "The air here is fresh and sweet while salty like sea air.");
set_listen("default", "You hear the soft rocking of the Ocean, calming you inside out.");
set_exits( (["east" : ROOMS "sandcastle7", "south" : ROOMS "sandcastle9"]) );
add_invis_exit("south");
}
