#include <std.h>
#include <security.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit LOCKER;
void create() {
    ::create();
    seteuid("VoteSave");
    set_path("/adm/save/votes/guilds");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set("short", "Locker Room");
    set("long", "Welcome to the Guild Storage Shop! Large crates are lined neatly behind the counter. All the crates are numbered and have locked doors on the front. This shop charges for storing items. Use the command <store> to leave an item for storage and <reclaim> to retrieve a stored item. Only one item may be stored per player.");
    set_items( ([ "crate" : "Large wooden boxes with locked doors." ]) );
    set_exits((["down" : GROOM"board_room", "east" : "/d/guilds/treasury", "up" : "/d/guilds/leadermeet"]));
}
