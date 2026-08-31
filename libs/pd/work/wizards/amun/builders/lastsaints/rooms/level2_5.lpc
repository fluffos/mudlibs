#include <std.h>
#include <amun.h>
inherit LOCKER;
void create() {
    set_path("/adm/save/votes/lastsaintsstorage");
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Last Saints Storage Room");
    set("long", "%^BOLD%^%^WHITE%^The Last Saints storage room. Lockers cover the 4 walls and each is labeled with a name. Members may %^RED%^<store [item]> %^WHITE%^and %^RED%^<reclaim> %^WHITE%^it later.%^RESET%^");
    set_exits((["east" : GUILDROOM+"level2_2"]));
}
