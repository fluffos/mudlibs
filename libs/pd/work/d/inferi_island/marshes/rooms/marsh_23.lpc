#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Rocks lay in the middle of the path, hindering people to move around them. They are slippery from the rain that has fallen already. The wind begins to pick up making the temperature drop slightly. A large %^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^RESET%^%^MAGENTA%^h%^BOLD%^%^YELLOW%^t%^WHITE%^e%^YELLOW%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^n%^WHITE%^g %^BLACK%^bolt hits the side of the mountain causing rocks to fall to the south.%^RESET%^");
    set_exits( ([ "east" : MARSHROOM+"marsh_19", "north" : MARSHROOM+"marsh_24" ]) );
    add_pre_exit_function("east", "go_east");
    add_pre_exit_function("north", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("raknid", this_object()))
	new(MARSHMON+"inferi_raknid")->move(this_object());
    if (!present("centaur", this_object()))
	new(MARSHMON+"inferi_centaur")->move(this_object());
}
int go_east() {
    if(!this_player()->is_player()) return 0;
    return 1;
}
