#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^Bloody entrails of women and young children dangle from the walls and ceilings. Many insects swarm around, feasting on anything around it, dead or alive. Maggots chew through the many bloody corpses that have been slewn around. No sane creature would ever purposely step foot into such a vile and sick place as this.%^RESET%^");
    set_items( ([ "path": "%^RESET%^%^RED%^This path looks as if it is stained with years of blood.%^RESET%^", "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^" ]) );
    set_exits( ([ "southwest": HELLROOM+"eye_of_hell_1", "northeast": HELLROOM+"eye_of_hell_41" ]) );
}
void reset() {
    ::reset();
    if (!present("demon", this_object()))
	new(HELLMON+"hell_demon")->move(this_object());
    if (!present("demon", this_object()))
	new(HELLMON+"hell_demon")->move(this_object());
}
