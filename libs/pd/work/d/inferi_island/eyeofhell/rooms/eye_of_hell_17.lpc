#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^In this very room are the decayed remains of the tortured victims from the previous punishments. In the middle of this room lies a unique chair and at a closer look, a mutilated head is stuck to the side of the chair. %^RED%^Blood %^BLACK%^is splattered everywhere causing passerbys to feel sick to their stomach. The desire to leave this room is great as %^RED%^blood %^BLACK%^is falling from the ceiling. The crack from a whip can be heard as a new victim is getting tortured.%^RESET%^");
    set_items( ([ "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^" ]) );
    set_exits( ([ "southwest": HELLROOM+"eye_of_hell_16", "northeast": HELLROOM+"eye_of_hell_18"  ]) );
}
void reset() {
    ::reset();
    if (!present("sinner", this_object()))
	new(HELLMON+"sinner")->move(this_object());
    if (!present("sinner", this_object()))
	new(HELLMON+"sinner")->move(this_object());
}
