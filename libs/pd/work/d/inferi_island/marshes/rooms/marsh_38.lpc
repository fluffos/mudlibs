#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Rocks lay in the middle of the path, hindering people to move around them. They are slippery from the rain that has fallen already. The wind begins to pick up making the temperature drop slightly. A large %^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^RESET%^%^MAGENTA%^h%^BOLD%^%^YELLOW%^t%^WHITE%^e%^YELLOW%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^n%^WHITE%^g %^BLACK%^bolt hits the side of the mountain causing rocks to fall to the south.%^RESET%^");
    set_exits( ([ "west" : MARSHROOM+"marsh_37", "north" : MARSHROOM+"marsh_39" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("ferrel", this_object()))
	new(MARSHMON+"inferi_ferrel")->move(this_object());
    if (!present("minotaur", this_object()))
	new(MARSHMON+"inferi_minotaur")->move(this_object());
    if (!present("giant", this_object()))
	new(MARSHMON+"inferi_giant")->move(this_object());
}
