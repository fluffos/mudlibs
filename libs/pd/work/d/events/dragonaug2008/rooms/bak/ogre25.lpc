#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Shadows dance off the cave walls as if moving to a slow internal beat.  Although the darkness slinks into the corners of the area, small %^WHITE%^white crystals %^BLACK%^peek out from the crevices, allowing the cavern to be magically %^WHITE%^lit%^BLACK%^.  Tiny droplets of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^trickle down the maze of %^WHITE%^crystals %^BLACK%^toward a little %^BLUE%^pool %^BLACK%^on the rock floor.  The %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^sings a soft song against the ground, providing more rhythm for the dancing shadows.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre19", "southeast" : DRAG_ROOMS "ogre30" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre5", this_object()))
	new(DRAG_MOBS "ogre5")->move(this_object());
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());
}
