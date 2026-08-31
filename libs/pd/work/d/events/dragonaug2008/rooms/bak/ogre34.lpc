#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Despite the musty feeling, a small breeze flows in through a small hole in the side of the cave walls.  Rock formed ice cycles dangle dangerously from the ceiling of the cave, waiting to puncture anyone who disturbs their slumber.  %^WHITE%^Crystals %^BLACK%^are embedded into every crevice, and they hang down over a low bridge in the ceiling.  Stalagmites and stalactites litter either side of the path, making it even more prevalent.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre27", "south" : DRAG_ROOMS "ogre39" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre6", this_object()))
	new(DRAG_MOBS "ogre6")->move(this_object());
    if (!present("ogre8", this_object()))
	new(DRAG_MOBS "ogre8")->move(this_object());
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
}
