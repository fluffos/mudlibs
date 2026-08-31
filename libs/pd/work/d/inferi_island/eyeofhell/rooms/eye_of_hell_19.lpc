#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^In this eye of hell, the minions of darkness gather and plot on the destruction of souls. The walls are coated with fresh %^RED%^blood%^BLACK%^. The ground squishes under each step, giving the feeling that the dead rotten souls bled through the ground forming a hellacious walkway. Flaming skulls of the damned seem to be the 'eyes' main lightsource.%^RESET%^");
    set_items( ([ "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^", "skulls": "%^BOLD%^%^RED%^These skulls were made from the decapitated heads of the lost souls.%^RESET%^" ]) );
    set_exits( ([ "southwest": HELLROOM+"eye_of_hell_18", "northeast": HELLROOM+"eye_of_hell_20"  ]) );
}
void reset() {
    ::reset();
    if (!present("demon", this_object()))
	new(HELLMON+"hell_demon")->move(this_object());
    if (!present("demon", this_object()))
	new(HELLMON+"hell_demon")->move(this_object());
    if (!present("sinner", this_object()))
	new(HELLMON+"sinner")->move(this_object());
    if (!present("sinner", this_object()))
	new(HELLMON+"sinner")->move(this_object());
}
