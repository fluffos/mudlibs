#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The cavern is enormous and dark. The sound of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^gently dripping from the ceiling echoes loudly throughout the empty cave. The only source of %^WHITE%^light %^BLACK%^in these depths are %^WHITE%^white crystals%^BLACK%^ lining the walls, somehow giving off %^WHITE%^light %^BLACK%^and allowing one to see enough to find a single pathway through the middle of the cave. Stalagmites and stalactites litter either side of the path, making it even more prevalent.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre1", "southwest" : DRAG_ROOMS "ogre7" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());
    if (!present("ogre7", this_object()))
	new(DRAG_MOBS "ogre7")->move(this_object());
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
}
