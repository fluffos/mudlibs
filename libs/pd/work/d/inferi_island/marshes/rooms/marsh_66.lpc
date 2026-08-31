#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^There is a small patch of shrubs along side the mountain that is on %^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e. There are a combined group of noises with the thunder, the v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s and the sound of voices. The ground becomes a little slippery as a few raindrops begin to fall, making it harder to walk. A few caves can be seen up the mountain.%^RESET%^");
    set_items( ([ "shrubs": "%^BOLD%^%^BLACK%^These shrubs are blazing with fire." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_67", "west" : MARSHROOM+"marsh_65" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
