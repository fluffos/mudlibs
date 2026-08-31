#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^A crystalline light system seems to be, for the most part, absent from this room.  A faint concentration of %^RESET%^%^ORANGE%^gold flickering dust %^BOLD%^%^BLACK%^can be seen fluttering from the cracks in the ceiling to the floor, %^RESET%^%^ORANGE%^lighting %^BOLD%^%^BLACK%^up a tolerable path through the cave.  A bat screeches and winds through cracks in the ceiling, bouncing back and forth on the cave walls as a symphony of sound.  Sitting side by side is a couple of boulders covered in %^YELLOW%^glittering gold%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "east" : DRAG_ROOMS "ogre37", "west" : DRAG_ROOMS "ogre35" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre9", this_object()))
	new(DRAG_MOBS "ogre9")->move(this_object());
}
