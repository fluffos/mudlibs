#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Thunder rolls in the %^BOLD%^%^BLACK%^blackened sky %^RESET%^%^ORANGE%^causing everything around to tremble. There is a slight, humid, breeze causing the smell of rotten flesh and blood to encompass the area. A glimpse of something golden can be seen to the far north. A loud BANG is heard from the clouds above.%^RESET%^");
    set_exits( ([ "northeast" : MARSHROOM+"BM_60", "southwest" : MARSHROOM+"BM_24" ]) );
    add_pre_exit_function("northeast", "sp_sap");
    add_pre_exit_function("southwest", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("centaur", this_object()))
	new(MARSHMON+"inferi_centaur")->move(this_object());
    if (!present("halfelf", this_object()))
	new(MARSHMON+"inferi_halfelf")->move(this_object());
    if (!present("sauran", this_object()))
	new(MARSHMON+"inferi_sauran")->move(this_object());
    if (!present("dwarf", this_object()))
	new(MARSHMON+"inferi_dwarf")->move(this_object());
}
