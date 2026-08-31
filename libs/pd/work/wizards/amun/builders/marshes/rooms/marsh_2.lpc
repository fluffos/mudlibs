#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The jagged rocks smell of blood and death. There are stray pieces of rotten flesh lying along the small path warning passerbys. Giant bugs can be seen moving around in search of their next meal. A v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e %^BLACK%^swoops down and grabs part of the rotting flesh.%^RESET%^");
    set_items( ([ "flesh": "%^BOLD%^%^BLACK%^This is the flesh of the ones who have died here recently." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_1", "west": MARSHROOM+"marsh_3" ]) );
    add_pre_exit_function("east", "go_east");
}
int go_east() {
    if(!this_player()->is_player()) return 0;
    return 1;
}
