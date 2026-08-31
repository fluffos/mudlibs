#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^This room is riddled with petrifying sights. Many maggots can be seen feasting upon corpses of the dead and the living. As if losing hope for help, one corpse finally loses his will to fight and dies. Soulwreckers roam about stealing the souls of the damned and devouring what is seen at first sight.%^RESET%^");
    set_items( ([ "maggots": "%^RESET%^%^RED%^The maggots feast on all of the rotting flesh they can find.%^RESET%^" ]) );
    set_exits( ([ "northwest": HELLROOM+"eye_of_hell_4", "southeast": HELLROOM+"eye_of_hell_6" ]) );
}
void reset() {
    ::reset();
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
}
