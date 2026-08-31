#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The path subsides causing the water to be the only way to move on. The water is shallow enough, but there are dead corpses floating around in it. The water is very mucky and looks like it will take more effort to walk through than on land. One of the corpses opens their eyes.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "south" : MARSHROOM+"BM_7", "north" : MARSHROOM+"BM_11", "northeast" : MARSHROOM+"BM_21" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("goblin", this_object()))
	new(MARSHMON+"inferi_goblin")->move(this_object());
    if (!present("orc", this_object()))
	new(MARSHMON+"inferi_orc")->move(this_object());
    if (!present("gremlin", this_object()))
	new(MARSHMON+"inferi_gremlin")->move(this_object());
}
