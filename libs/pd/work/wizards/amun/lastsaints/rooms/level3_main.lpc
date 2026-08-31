#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Last Saints");
    set("long", "%^BOLD%^%^WHITE%^The third floor of the Last Saints seems to be very active as many things can be heard around this room. There are shops in every direction awaiting buisness, and there is a lot of noise coming from the fourth floor.%^RESET%^");
    set_exits( ([ "down" : GUILDROOM+"last_saints_board", "southwest" : GUILDROOM+"armour_room", "west" : GUILDROOM+"heal_shop", "east" : GUILDROOM+"object_room", "southeast" : GUILDROOM+"weapon_room", "south" : GUILDROOM+"level3_1", "up" : GUILDROOM+"level4_main" ]) );
}
