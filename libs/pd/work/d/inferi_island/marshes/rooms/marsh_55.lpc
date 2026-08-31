#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path becomes wider towards the south and offers more room to roam around. The v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s can be seen swooping down to the west grabbing more rotten flesh and taking flight again. The wind picks up the bigger the path becomes. A bolt of %^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^RESET%^%^MAGENTA%^h%^BOLD%^%^YELLOW%^t%^WHITE%^e%^YELLOW%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^n%^WHITE%^g brightens %^BLACK%^the sky, then subsides.%^RESET%^");
    set_exits( ([ "west" : MARSHROOM+"marsh_54", "south" : MARSHROOM+"marsh_56" ]) );
    add_pre_exit_function("west", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
