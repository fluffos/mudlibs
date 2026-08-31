#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A large depression lies in the path ahead. However, on closer inspection it is actually the footprint of a large dragon. The rocks rise high, like walls, on either side of the path closing it in uncomfortably. A harp turn towards the west cuts off a further view of the path. Overhead the clouds thicken into a dark sea of gray.%^RESET%^ ");
    set_exits( ([ "east" : MARSHROOM+"marsh_40", "west" : MARSHROOM+"marsh_42" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("netherman", this_object()))
	new(MARSHMON+"inferi_netherman")->move(this_object());
    if (!present("skeleton", this_object()))
	new(MARSHMON+"skeleton")->move(this_object());
}
