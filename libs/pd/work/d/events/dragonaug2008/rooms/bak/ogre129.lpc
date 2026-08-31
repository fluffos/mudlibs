#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^YELLOW%^%^Dust the color of gold %^BLACK%^sprinkles across the ground like a %^YELLOW%^carpet of shimmer%^BLACK%^.  What looks like rock formed coral sits along the sides of the cavern walls.  Although the darkness slinks into the corners of the area, small %^WHITE%^white crystals %^BLACK%^peek out from the crevices, allowing the cavern to be magically %^WHITE%^lit%^BLACK%^.  A small %^BLUE%^pool of water %^BLACK%^provides the illusion of a never ending room with its reflections.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "west" : DRAG_ROOMS "ogre128", "north" : DRAG_ROOMS "ogre116", "east" : DRAG_ROOMS "ogre130" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre9", this_object()))
	new(DRAG_MOBS "ogre9")->move(this_object());
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
}
