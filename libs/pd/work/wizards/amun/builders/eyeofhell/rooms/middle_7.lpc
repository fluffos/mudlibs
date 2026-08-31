#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The land is flat and broken and the soil is dry and stained with blood. Everything seems bleak and hopeless, the air thick with despair. Standing guard to the west is a lone guillotine, its blade coated with gore. A pile of headless corpses lay rotting beside it. The heads are thrust upon pikes which rise from the ground, each face locked in a moment of torture.%^RESET%^");
    set_exits( ([ "south": HELLROOM+"middle_6", "northeast": HELLROOM+"middle_8" ]) );
}
void reset() {
    ::reset();
    if (!present("wizard", this_object()))
	new(HELLMON+"powerful_wizard")->move(this_object());
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
}
