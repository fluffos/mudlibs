#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^Endless screams pierce the unrelenting darkness that fills this area. Everything in this room is sticky and warm. Flies choke the air, feasting apon flesh and %^RED%^blood%^BLACK%^. Something slithers along the ground, and a loud hiss comes from behind. Rising above it all is laughter, hideous mocking laughter. Light has no place here and never has, darkness rules all.%^RESET%^");
    set_exits( ([ "southwest": HELLROOM+"middle_9", "north": HELLROOM+"middle_11" ]) );
}
void reset() {
    ::reset();
    if (!present("wizard", this_object()))
	new(HELLMON+"powerful_wizard")->move(this_object());
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
}
