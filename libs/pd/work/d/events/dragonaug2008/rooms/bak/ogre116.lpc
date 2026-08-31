#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^WHITE%^The light in this turn of the cave is so overpowering that even some creatures would need to cover their eyes.  An absence of regular stone and an excess of white crystals create a blinding aura which is inescapable.  There are %^YELLOW%^golden flakes %^WHITE%^littering every inch of the room, which adds to the visual discomfort.  Although there are no shadows in this room, an odd sense that there are lurkers remain.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "south" : DRAG_ROOMS "ogre129", "west" : DRAG_ROOMS "ogre115", "north" : DRAG_ROOMS "ogre105", "east" : DRAG_ROOMS "ogre117" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());
    if (!present("ogre8", this_object()))
	new(DRAG_MOBS "ogre8")->move(this_object());
    if (!present("ogre6", this_object()))
	new(DRAG_MOBS "ogre6")->move(this_object());
}
