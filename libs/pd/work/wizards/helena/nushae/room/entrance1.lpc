#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 3, "night light" : 2, "beach" : 1, "no attack" : 1, "no bump" : 1]) );
    set_short("NuShae entrance");
    set_listen("default", "The soft lulling of the ocean's current is heard.");
    set_smell("default", "The water smells refreshing.");
    set_long("This is the entrance beach to the grand city of NuShae. This is a rich city full of culture and life, mermaids and mermen. To the east you see bustle and hustle of the busy city square. To the west is the cliff wall, and what seems to be scaleable wall, as if someone has purposely carved out climbing footholds and handholds.");
    set_night_long("This is the entrance beach to the grand city of NuShae. This rich city full of culture and life seems to be lit up with amazing lights, even in the dark of night. To the east you see the bright lights which glow with a magical brightness. To the west is the cliff wall, and what seems to be scaleable wall, as if someone has purposely carved out climbing footholds and handholds.");
    set_items((["room" : "There is not much here too look at, just sand and the water currents flowing by.", "ceiling" : "There is no ceiling here: You are in the ocean.", "floor" : "The floor is the seabed floor, sand, seaweed and yet more sand.", "footholds" : "They seem to have been deliberately carved out of the rock wall, as if someone was creating a means to escape.", "handholds" : "They seem to have been deliberately carved out of the rock wall, as if someone was creating a means to escape.", "walls" : "The surrounding walls of rock are hard, grey, and solid."]));
    set_exits( (["east" : ROOMS "t1"]) );
}
