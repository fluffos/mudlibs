#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Hanging off of the ceiling are sharply daggered rock formed ice cycles daring someone to make a sound.  Tiny droplets of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^trickle down the maze of %^WHITE%^crystals %^BLACK%^toward a little %^BLUE%^pool %^BLACK%^on the rock floor.   %^YELLOW%^Dust %^BLACK%^the color of %^YELLOW%^gold %^BLACK%^sprinkles across the ground like a %^YELLOW%^carpet of shimmer%^BLACK%^.  A small %^BLUE%^pool of water %^BLACK%^provides the illusion of a never ending room with its reflections.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre26", "west" : DRAG_ROOMS "ogre32" ]) );
}
