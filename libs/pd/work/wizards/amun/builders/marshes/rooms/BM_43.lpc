#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The path of the marsh is riddled with %^BOLD%^%^BLACK%^dark %^RESET%^%^ORANGE%^and murky water. A decrepit w%^RED%^o%^ORANGE%^oden b%^RED%^r%^ORANGE%^idge can be seen to the east, but is broken offering no way across with ease. A body, severed at the waist, crawls through the thick reeds in the water. A sudden strong gust of wind causes a few pieces from the b%^RED%^r%^ORANGE%^idge to fall into the water with a noisy splash, sending some small creature into a flight of terror.%^RESET%^");
    set_items( ([ "bridge": "%^BOLD%^%^BLACK%^This bridge is old and worn. It is broken half way through the marsh.", "body": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM+"BM_37" ]) );
}
void reset() {
    ::reset();
    if (!present("goblin", this_object()))
	new(MARSHMON+"inferi_goblin")->move(this_object());
    if (!present("orc", this_object()))
	new(MARSHMON+"inferi_orc")->move(this_object());
    if (!present("gremlin", this_object()))
	new(MARSHMON+"inferi_gremlin")->move(this_object());
    if (!present("raknid", this_object()))
	new(MARSHMON+"inferi_raknid")->move(this_object());
}
