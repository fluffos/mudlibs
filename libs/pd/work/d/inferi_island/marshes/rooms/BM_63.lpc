#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^To the north, the glimpse of %^BOLD%^%^YELLOW%^gold %^RESET%^%^ORANGE%^that was seen before has taken shape into a pyramid. An arrow shoots by and lands to the west. A man can been seen through a hole of the pyramid with his bow at ease. He apparently is protecting something or someone.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "north" : MARSHROOM+"BM_64" ]) );
}
void reset() {
    ::reset();
    if (!present("goblin", this_object()))
	new(MARSHMON+"inferi_goblin")->move(this_object());
    if (!present("orc", this_object()))
	new(MARSHMON+"inferi_orc")->move(this_object());
    if (!present("skeleton", this_object()))
	new(MARSHMON+"skeleton")->move(this_object());
    if (!present("corpse", this_object()))
	new(MARSHMON+"undead_corpse")->move(this_object());
}
