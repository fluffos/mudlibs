#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^A small wand planted here and there shows where the path zigzags from tuft to tuft of %^GREEN%^green-scummed %^ORANGE%^pits and foul quagmires. Rank reeds and lush, %^GREEN%^slimy water-plants %^ORANGE%^send an odor of decay and a heavy miasmatic vapor into the air, while a false step of wanderers can plunge them thigh-deep into the %^BOLD%^%^BLACK%^dark quivering mire%^RESET%^%^ORANGE%^. Tenaciously, its grip plucks heels causing stray souls to sink as if some malignant hand was tugging them down into those obscene depths.%^RESET%^ ");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "south" : MARSHROOM+"BM_9", "southeast" : MARSHROOM+"BM_23", "northeast" : MARSHROOM+"BM_19", "north" : MARSHROOM+"BM_13", ]) );
    add_pre_exit_function("south", "sp_sap");
    add_pre_exit_function("north", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("halfelf", this_object()))
	new(MARSHMON+"inferi_halfelf")->move(this_object());
    if (!present("sauran", this_object()))
	new(MARSHMON+"inferi_sauran")->move(this_object());
}
