#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The darkness in this room is overwhelming, yet %^YELLOW%^light %^BLACK%^somehow emerges through.  Most of the stones seem to be made of the darkest onyx possible, battling the few %^WHITE%^white crystals %^BLACK%^trying to create %^WHITE%^light%^BLACK%^.  The lighting in the room changes with every footstep, overpowering visual senses with confusion.  A dusty skeleton of some sort of creature leans against a rock, something left to die.  Bats soar above to different surfaces they can hang from, screeching occasionally.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "west" : DRAG_ROOMS "ogre140", "northeast" : DRAG_ROOMS "ogre128" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());
    if (!present("ogre5", this_object()))
	new(DRAG_MOBS "ogre5")->move(this_object());
}
