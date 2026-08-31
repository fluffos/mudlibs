#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Thunder rolls in the %^BOLD%^%^BLACK%^blackened sky %^RESET%^%^ORANGE%^causing everything around to tremble. There is a slight, humid, breeze causing the smell of rotten flesh and blood to encompass the area. A glimpse of something golden can be seen to the far north. A loud BANG is heard from the clouds above.%^RESET%^");
    set_exits( ([ "east" : MARSHROOM+"BM_32", "southwest" : MARSHROOM+"BM_40" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("southwest", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("halfling", this_object()))
	new(MARSHMON+"inferi_halfling")->move(this_object());
    if (!present("weimic", this_object()))
	new(MARSHMON+"inferi_weimic")->move(this_object());
}
