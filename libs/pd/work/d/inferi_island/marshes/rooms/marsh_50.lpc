#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Thunder rolls above the mountains causing the rocks to tremble. There is a small humid breeze causing the smell of rotten flesh and blood to encompass the area. A glimpse of something golden can be seen to the far north. A loud BANG is heard from the clouds above.%^RESET%^");
    set_exits( ([ "south" : MARSHROOM+"marsh_49", "east" : MARSHROOM+"marsh_51" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("ogre", this_object()))
	new(MARSHMON+"inferi_ogre")->move(this_object());
    if (!present("goblin", this_object()))
	new(MARSHMON+"inferi_goblin")->move(this_object());
}
