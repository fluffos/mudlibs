#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path begins to slant down in all directions. The marshes can be seen from this area, with the marsh water %^RESET%^%^GREEN%^glowing %^BOLD%^%^BLACK%^and the shrubs brown in vegetation. A few dragons fly over the mountains causing them to go silent. At least they are moving away from the mountains and moving towards the ocean.%^RESET%^");
    set_items( ([ "dragons": "%^BOLD%^%^BLACK%^They seem to be moving with haste, they must be running from something big." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_6", "south": MARSHROOM+"marsh_8" ]) );
}
