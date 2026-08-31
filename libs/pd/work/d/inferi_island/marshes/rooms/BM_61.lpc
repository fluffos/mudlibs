#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The path becomes wider towards the north and offers more room to roam around. The %^BOLD%^%^BLACK%^v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s %^RESET%^%^ORANGE%^can be seen swooping down to the west grabbing rotten flesh and taking flight again. The wind picks up the bigger the path becomes. A bolt of %^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^RESET%^%^MAGENTA%^h%^BOLD%^%^YELLOW%^t%^WHITE%^e%^YELLOW%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^n%^WHITE%^g brightens %^RESET%^%^ORANGE%^%^the sky, then subsides.%^RESET%^");
    set_exits( ([ "southeast" : MARSHROOM+"BM_51", "west" : MARSHROOM+"BM_66" ]) );
    add_pre_exit_function("west", "sp_sap");
    add_pre_exit_function("southeast", "sp_sap");
}
