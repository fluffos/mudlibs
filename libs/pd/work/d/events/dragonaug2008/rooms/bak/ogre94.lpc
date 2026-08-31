#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^This stretch of cave is significantly hotter than most other areas.  Holes cover the ceiling and walls, from which a sort of steam seems to escape.  Particles of %^YELLOW%^gold dust %^BLACK%^flicker through the steam, causing large bursts of %^WHITE%^light hitting the crystals%^BLACK%^.  Thousands of small insects can be seen in the steam, floating aimlessly through the air.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "southeast" : DRAG_ROOMS "ogre106", "southwest" : DRAG_ROOMS "ogre105" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre8", this_object()))
	new(DRAG_MOBS "ogre8")->move(this_object());
    if (!present("ogre7", this_object()))
	new(DRAG_MOBS "ogre7")->move(this_object());
}
