#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^A fresh trail of blood crosses the path here. Strangely, the blood-trail veers around the corner, behind some jagged rocks. Strange noises, like something being eaten, can be heard coming from behind these rocks. A small tower of skulls and a %^BLACK%^long black spear%^RED%^, which pierces the bone holding them upright, forces the trail to veer around it. Bats fly down in search of their master.%^RESET%^");
    set_items( ([ "skulls": "%^RESET%^%^RED%^These are the rotton skulls of the dead souls.%^RESET%^" ]) );
    set_exits( ([ "west": HELLROOM+"middle_40", "east": HELLROOM+"middle_42" ]) );
}
void reset() {
    ::reset();
    if (!present("horseman", this_object()))
	new(HELLMON+"headless_horseman")->move(this_object());
    if (!present("centaur", this_object()))
	new(HELLMON+"black_centaur")->move(this_object());
    if (!present("lich", this_object()))
	new(HELLMON+"lich")->move(this_object());
}
