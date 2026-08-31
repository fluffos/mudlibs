#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^A faint red mist clouds the senses and the smell of death and decay is everywhere. Twisted and mangled bodies hang from their noses that are tied to the ceiling. Moans can be heard from the bodies, and the occasional eye follows the progress of passerbys. A line of rotting corpses make the pathway hard to follow.%^RESET%^");
    set_exits( ([ "southwest": HELLROOM+"eye_of_hell_20", "northeast": HELLROOM+"eye_of_hell_22"  ]) );
}
void reset() {
    ::reset();
    if (!present("demon", this_object()))
	new(HELLMON+"hell_demon")->move(this_object());
    if (!present("demon", this_object()))
	new(HELLMON+"hell_demon")->move(this_object());
}
