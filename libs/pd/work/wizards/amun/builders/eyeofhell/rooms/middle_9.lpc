#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^Broken jagged rocks gives way to dark soil. Thick dry weeds sprout from the dusty earth, bearing rotten fruit. A scarecrow, stitched from patches of flesh, has been propped up on a pole, with a two headed crow mockingly sitting on its shoulder. The weeds rock and sway though there is no breeze and small creatures scuttle underfoot.%^RESET%^");
    set_exits( ([ "south": HELLROOM+"middle_8", "northeast": HELLROOM+"middle_10" ]) );
}
void reset() {
    ::reset();
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
    if (!present("wolf", this_object()))
	new(HELLMON+"werewolf")->move(this_object());
    if (!present("banshee", this_object()))
	new(HELLMON+"banshee")->move(this_object());
}
