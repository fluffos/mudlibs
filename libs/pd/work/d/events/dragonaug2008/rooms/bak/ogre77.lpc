#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Small %^WHITE%^sparkles %^BLACK%^trickle along the cave walls, as if there were a million %^WHITE%^f%^YELLOW%^i%^WHITE%^refli%^YELLOW%^e%^WHITE%^s%^BLACK%^ lighting the way for onlookers.  Rock formed ice cycles dangle dangerously from the ceiling of the cave, waiting to puncture anyone who disturbs their slumber.  %^YELLOW%^Dust the color of gold %^BLACK%^sprinkles across the ground like a %^YELLOW%^carpet of shimmer%^BLACK%^.  Despite the musty feeling, a small breeze flows in through a small hole in the side of the cave walls.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "south" : DRAG_ROOMS "ogre95", "east" : DRAG_ROOMS "ogre78" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre9", this_object()))
	new(DRAG_MOBS "ogre9")->move(this_object());
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
    if (!present("ogre7", this_object()))
	new(DRAG_MOBS "ogre7")->move(this_object());
}
