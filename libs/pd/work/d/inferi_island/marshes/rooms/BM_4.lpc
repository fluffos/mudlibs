#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Thunder rolls in the %^BOLD%^%^BLACK%^blackened sky %^RESET%^%^ORANGE%^causing everything things around to tremble. There is a small humid breeze causing the smell of rotten flesh and blood to encompass the area. A glimpse of something golden can be seen to the far north. A loud BANG is heard from the clouds above.%^RESET%^");
    set_exits( ([ "southwest" : MARSHROOM+"BM_6", "north" : MARSHROOM+"BM_44", "northeast" : MARSHROOM+"BM_52", "southeast" : MARSHROOM+"BM_2" ]) );
    add_pre_exit_function("southeast", "sp_sap");
    add_pre_exit_function("southwest", "sp_sap");
}
