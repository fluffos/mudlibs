#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^There are cages built into the walls offering a home for the damned. Whips and chains hang from the walls and they look worn and dirty. %^RED%^Torturing %^BLACK%^devices lay around the middle of the path, making it harder to move. A hand from a cage reaches out in search for help.%^RESET%^");
    set_items( ([ "cages": "%^BOLD%^%^BLACK%^These cages were built to hold recent and new tortured souls.%^RESET%^", "hand": "%^BOLD%^%^BLACK%^This is the hand of a sad soul searching for help.%^RESET%^" ]) );
    set_exits( ([ "west": HELLROOM+"eye_of_hell_34", "east": HELLROOM+"eye_of_hell_32" ]) );
}
void reset() {
    ::reset();
    if (!present("gargoyle", this_object()))
	new(HELLMON+"gargoyle")->move(this_object());
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
    if (!present("lich", this_object()))
	new(HELLMON+"lich")->move(this_object());
}
