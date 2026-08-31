#include <std.h>
inherit LOCKER;

void create() {
    set_path("/adm/save/votes/darksoulstorage");
    ::create();
    set_properties(([ "light":1, "night light":1, "no steal":1, "no bump":1, "no castle":1, "no attack":1, "no teleport":1 ]));
    set("short", "Darksoul Storage Room");
    set("long",
        "%^BOLD%^%^BLACK%^Large crates are stacked neatly behind a counter.  "
        "All the %^BOLD%^%^BLACK%^crates are numbered and have hinged doors on the front.  This %^BOLD%^%^BLACK%^shop charges "
        "for storing items.  Use the command <store> to %^BOLD%^%^BLACK%^leave an item for storage and <reclaim> "
        "to retrieve a stored %^BOLD%^%^BLACK%^item.  Only one item may be stored per player.");
    set_items( ([ "crate" : "Large wooden boxes with locked doors." ]) );
    set_exits(([
      "east" : "/d/guilds/darksoul/dungeon"
    ]));
}
