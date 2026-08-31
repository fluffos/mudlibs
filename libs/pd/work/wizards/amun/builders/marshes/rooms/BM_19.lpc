#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Thunder rolls in the %^BOLD%^%^BLACK%^blackened sky %^RESET%^%^ORANGE%^causing everything around to tremble. There is a slight, humid, breeze causing the smell of rotten flesh and blood to encompass the area. A glimpse of something golden can be seen to the far north. A loud BANG is heard from the clouds above.%^RESET%^");
    set_exits( ([ "south" : MARSHROOM+"BM_21", "north" : MARSHROOM+"BM_17" , "southwest" : MARSHROOM+"BM_11" ]) );
}
void reset() {
    ::reset();
    if (!present("nymph", this_object()))
	new(MARSHMON+"inferi_nymph")->move(this_object());
    if (!present("corpse", this_object()))
	new(MARSHMON+"undead_corpse")->move(this_object());
}
