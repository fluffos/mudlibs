#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^A faint red mist clouds the senses and the smell of death and decay is everywhere. Twisted and mangled bodies hang from their noses that are tied to the ceiling. Moans can be heard from the bodies, and the occasional eye follows the progress of passerbys. A line of rotting corpses make the pathway hard to follow.%^RESET%^");
    set_exits( ([ "west": HELLROOM+"eye_of_hell_10", "east": HELLROOM+"eye_of_hell_12"  ]) );
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
