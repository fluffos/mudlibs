#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("outdoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^CYAN%^Standing back outside, the uneasy feeling has subsided. Other patios can be seen towards the east and west, but most of the travelers seem to have left.  To the west, there is a small dome in the dirt; looking east, the same dome like structure can be seen.  It is a beautiful day outside.\n");
    set_exits( ([ "northwest" : ROOMS+"hamen_tomb_6"]) );
}
void reset() {
    ::reset();
    if (!present("tree", this_object()))
	new(MON+"tree_of_life")->move(this_object());
    if (!present("falcon", this_object()))
	new(MON+"falcon")->move(this_object());
    if (!present("camel", this_object()))
	new(MON+"camel")->move(this_object());
    if (!present("mule", this_object()))
	new(MON+"mule")->move(this_object());
}
