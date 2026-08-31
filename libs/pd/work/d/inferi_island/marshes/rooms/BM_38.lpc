#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^To the north, the glimpse of %^BOLD%^%^YELLOW%^gold %^RESET%^%^ORANGE%^that was seen before has taken shape into a pyramid. An arrow shoots by and lands to the west. A man can been seen through a hole of the pyramid with his bow at ease. He apparently is protecting something or someone.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"BM_36", "northwest" : MARSHROOM+"BM_40" ]) );
    add_pre_exit_function("northwest", "sp_sap");
    add_pre_exit_function("east", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("minotaur", this_object()))
	new(MARSHMON+"inferi_minotaur")->move(this_object());
    if (!present("ferrel", this_object()))
	new(MARSHMON+"inferi_ferrel")->move(this_object());
}
