#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A large depression lies in the path ahead. However, on closer inspection it is actually the footprint of a large dragon. The rocks rise high, like walls, on either side of the path closing it in uncomfortably. A sharp turn towards the west cuts off a further view of the path. Overhead the clouds thicken into a dark sea of gray.%^RESET%^ ");
    set_exits( ([ "south" : MARSHROOM+"marsh_25", "west" : MARSHROOM+"marsh_27" ]) );
    add_pre_exit_function("west", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("halfelf", this_object()))
	new(MARSHMON+"inferi_halfelf")->move(this_object());
    if (!present("sauran", this_object()))
	new(MARSHMON+"inferi_sauran")->move(this_object());
}
