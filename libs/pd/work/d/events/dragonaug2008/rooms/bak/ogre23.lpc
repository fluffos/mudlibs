#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The occasional drip of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^falling from the ceiling echoes throughout this room.  A scurrying sound from a rodent moving from its home to another can be heard.  Darkness plagues this room due to the scarcity of the white crystals, which illuminate the rest of the caves.  There appears to have been a lot of fighting here, as many rocks look as if they were thrown in battle.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre17", "southeast" : DRAG_ROOMS "ogre28" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
}
