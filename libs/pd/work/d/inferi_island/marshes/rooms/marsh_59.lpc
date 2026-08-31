#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^More broken, jagged land lies ahead. Heading into a giant boulder, the path has been cut through leaving a trail straight through the rock. The tunnel is not pitch black, instead, it has a faint %^RESET%^%^GREEN%^green glow which %^BOLD%^%^BLACK%^comes from large mushrooms growing out of the rock wall. Water trickles down the side of the tunnel walls and with each drip of water the mushrooms %^GREEN%^glow brighter%^BLACK%^. The wind blows through the tunnel turning the mushrooms into ash.%^RESET%^");
    set_exits( ([ "east" : MARSHROOM+"marsh_58", "west" : MARSHROOM+"marsh_60" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("sauran", this_object()))
	new(MARSHMON+"inferi_sauran")->move(this_object());
    if (!present("dwarf", this_object()))
	new(MARSHMON+"inferi_dwarf")->move(this_object());
}
