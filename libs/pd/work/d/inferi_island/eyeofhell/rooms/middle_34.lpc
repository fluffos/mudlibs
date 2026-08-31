#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^Death, gore and torment are the only words that are able to describe the terror laying ahead. Bodies lay strewn everywhere, hundreds, maybe thousands can be seen. The earth is stained dark with %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^with both new and old. Large demons stalk through the bodies, ripping off limbs to feast upon, whilst pale vampires suckle at open wounds from the freshly dead or dying.%^RESET%^");
    set_exits( ([ "south": HELLROOM+"middle_35", "north": HELLROOM+"middle_33" ]) );
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
