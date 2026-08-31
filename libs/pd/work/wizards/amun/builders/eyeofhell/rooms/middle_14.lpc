#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^Death, gore and torment are the only words that are able to describe the terror laying ahead. Bodies lay strewn everywhere, hundreds, maybe thousands can be seen. The earth is stained dark with %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^with both new and old. Large demons stalk through the bodies, ripping off limbs to feast upon, whilst pale vampires suckle at open wounds from the freshly dead or dying.%^RESET%^");
    set_exits( ([ "southwest": HELLROOM+"middle_13", "north": HELLROOM+"middle_15" ]) );
}
void reset() {
    ::reset();
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
    if (!present("gargoyle", this_object()))
	new(HELLMON+"gargoyle")->move(this_object());
    if (!present("lich", this_object()))
	new(HELLMON+"lich")->move(this_object());
}
