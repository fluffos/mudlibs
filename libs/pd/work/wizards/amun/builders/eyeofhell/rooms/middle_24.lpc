#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^Death, gore and torment are the only words that are able to describe the terror laying ahead. Bodies lay strewn everywhere, hundreds, maybe thousands can be seen. The earth is stained dark with %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^with both new and old. Large demons stalk through the bodies, ripping off limbs to feast upon, whilst pale vampires suckle at open wounds from the freshly dead or dying.%^RESET%^");
    set_exits( ([ "east": HELLROOM+"middle_25", "west": HELLROOM+"middle_23" ]) );
}
void reset() {
    ::reset();
    if (!present("horseman", this_object()))
	new(HELLMON+"headless_horseman")->move(this_object());
    if (!present("centaur", this_object()))
	new(HELLMON+"black_centaur")->move(this_object());
    if (!present("banshee", this_object()))
	new(HELLMON+"banshee")->move(this_object());
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
}
