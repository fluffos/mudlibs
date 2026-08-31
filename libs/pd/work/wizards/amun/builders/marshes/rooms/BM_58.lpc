#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The path of the marsh is riddled with %^BOLD%^%^BLACK%^dark %^RESET%^%^ORANGE%^and murky water. A decrepit w%^RED%^o%^ORANGE%^oden b%^RED%^r%^ORANGE%^idge can be seen to the east, but is broken offering no way across with ease. A body, severed at the waist, crawls through the thick reeds in the water. A sudden strong gust of wind causes a few pieces from the b%^RED%^r%^ORANGE%^idge to fall into the water with a noisy splash, sending some small creature into a flight of terror.%^RESET%^");
    set_items( ([ "bridge": "%^BOLD%^%^BLACK%^This bridge is old and worn. It is broken half way through the marsh.", "body": "These bodies are those of many races." ]) );
    set_exits( ([ "northeast" : MARSHROOM+"BM_66", "southeast" : MARSHROOM+"BM_65", "southwest" : MARSHROOM+"BM_48", "south" : MARSHROOM+"BM_56" ]) );
}
void reset() {
    ::reset();
    if (!present("nymph", this_object()))
	new(MARSHMON+"inferi_nymph")->move(this_object());
    if (!present("corpse", this_object()))
	new(MARSHMON+"undead_corpse")->move(this_object());
}
