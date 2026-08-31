#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path seems to grow more narrow causing the rocks to be utilized for balance or to be climbed on. The clouds above clap with thunder threatening to pour rain. From this area, a large marsh can be seen to the north. Something can be seen floating in its marshy waters.%^RESET%^");
    set_items( ([ "water": "%^BOLD%^%^BLACK%^There are dead faces in the water, these are the faces of those who came, fought and died.", "marsh": "%^RESET%^%^ORANGE%^This looks like a sad place full of death." ]) );
    set_exits( ([ "south" : MARSHROOM+"marsh_17", "north": MARSHROOM+"marsh_19" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre", this_object()))
	new(MARSHMON+"inferi_ogre")->move(this_object());
    if (!present("goblin", this_object()))
	new(MARSHMON+"inferi_goblin")->move(this_object());
}
