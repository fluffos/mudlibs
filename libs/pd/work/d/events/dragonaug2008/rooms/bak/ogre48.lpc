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
    set_exits( ([ "north" : DRAG_ROOMS "ogre43", "west" : DRAG_ROOMS "ogre47", "southwest" : DRAG_ROOMS "ogre57" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre8", this_object()))
	new(DRAG_MOBS "ogre8")->move(this_object());
}
