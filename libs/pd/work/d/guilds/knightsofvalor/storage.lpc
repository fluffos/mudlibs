#include <std.h>
inherit LOCKER;

void create() {
    set_path("/adm/save/votes/knightsofvalorstorage");
    ::create();
    set_properties( ([ "light" : 2, "no teleport":1, "indoors":1]) );
    set_short("Knights of Valor Storage Room");
    set_long("The Knights of Valor storage room is located directly under the treasury.  The treasurers have agreed to keep one item per Knight safe from all other hands.  There are wooden crates to keep each Knight's item separate and safe and ready to be used.  Members may <store [item]> and <reclaim> it later.");
    set_items( ([ "crate" : "The crates are all locked, your items are safe here." ]) );
    set_exits(([
      "up" : "/d/guilds/knightsofvalor/treasury"
    ]));
}
