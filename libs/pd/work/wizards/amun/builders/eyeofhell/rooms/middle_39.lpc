#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^Broken jagged rocks gives way to dark soil. Thick dry weeds sprout from the dusty earth, bearing rotten fruit. A scarecrow, stitched from patches of flesh, has been propped up on a pole, with a two headed crow mockingly sitting on its shoulder. The weeds rock and sway though there is no breeze and small creatures scuttle underfoot.%^RESET%^");
    set_exits( ([ "north": HELLROOM+"middle_26", "south": HELLROOM+"middle_38" ]) );
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
