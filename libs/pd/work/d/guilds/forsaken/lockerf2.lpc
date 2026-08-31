#include <std.h>

inherit LOCKER;

void create() {
    set_path("/adm/save/votes/forsakenstorage2");
    ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

    set("short", "Forsaken Storage Room");
    set("long",
        "Large crates are stacked neatly behind a counter.  "
        "All the crates are numbered and have hinged doors on the front.  This shop charges "
        "for storing items.  Use the command <store> to leave an item for storage and <reclaim> "
        "to retrieve a stored item.  Only one item may be stored per player.");
    set_items( ([ "crate" : "Large wooden boxes with locked doors." ]) );
    set_exits(([
     "down" : "/d/guilds/forsaken/lockerf",
    ]));
}
