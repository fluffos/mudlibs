#include <std.h>
#include <security.h>
#include <tirun.h>
inherit LOCKER;
void create() {
    set_path("/adm/save/votes/storage");
    ::create();
    set_path("/adm/save/votes/storage");
set_properties( ([ "light"   : 1,
               "indoors" :1,
           "no castle" : 1, ]) );
    set("short", "Locker Room");
    set("long",
        "Welcome to the storage shop.  Large crates are stacked neatly behind a counter.  "
        "All the crates are numbered and have hinged doors on the front.  This shop charges "
        "for storing items.  Use the command <store> to leave an item for storage and <reclaim> "
        "to retrieve a stored item.  Only one item may be stored per player.");
    set_items( ([ "crate" : "Large wooden boxes with locked doors." ]) );
    set_exits(([
      "down" : ROOMS"adv_enter"
    ]));
}
