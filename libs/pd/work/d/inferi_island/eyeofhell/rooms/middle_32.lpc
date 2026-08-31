#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^Old bones, which are the ribs of a long dead dragon, form a series of archways over the path. The soil here is black and dry, causing the ground to be filled with cracks and pits. The smell of rotting flesh is nearly overpowering, and inch long maggots scour the ground looking for something to feed on. Screams of pain and death carry through the foul breeze. Thick strands of silken web hang down from the archways, small dark spiders patrol them hungrily.%^RESET%^");
    set_items( ([ "web": "This web is huge in size and looks as if a giant spider created it.%^RESET%^" ]) );
    set_exits( ([ "south": HELLROOM+"middle_33", "north": HELLROOM+"middle_31" ]) );
}
void reset() {
    ::reset();
    if (!present("gargoyle", this_object()))
	new(HELLMON+"gargoyle")->move(this_object());
    if (!present("wizard", this_object()))
	new(HELLMON+"powerful_wizard")->move(this_object());
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
}
