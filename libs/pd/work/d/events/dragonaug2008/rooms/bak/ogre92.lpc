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
    set_exits( ([ "east" : DRAG_ROOMS "ogre93", "west" : DRAG_ROOMS "ogre91" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
    if (!present("ogre5", this_object()))
	new(DRAG_MOBS "ogre5")->move(this_object());
}
