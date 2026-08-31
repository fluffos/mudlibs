#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The path winds around a rather large, putrid smelling cliff. The cave is filled with jagged rocks hanging from ceiling, that look as if they could fall on anyone who passes. There are %^BLACK%^shadows %^RED%^bouncing off the walls, making it hard to see in all areas. The smell of blood and human flesh is fresh in the air.%^RESET%^");
    set_items( ([ "path": "%^RESET%^%^RED%^This path looks as if it is stained with years of blood.%^RESET%^", "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^", "cliff": "%^RESET%^%^ORANGE%^The cliff is full with rocks and shadows dancing off of them.%^RESET%^", "rocks": "%^RESET%^%^RED%^The rocks look as if they were used in battle.  There is some fresh flesh on a few of them." ]) );
    set_exits( ([ "west": HELLROOM+"eye_of_hell_33", "east": HELLROOM+"eye_of_hell_31" ]) );
}
void reset() {
    ::reset();
    if (!present("gargoyle", this_object()))
	new(HELLMON+"gargoyle")->move(this_object());
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
    if (!present("lich", this_object()))
	new(HELLMON+"lich")->move(this_object());
}
