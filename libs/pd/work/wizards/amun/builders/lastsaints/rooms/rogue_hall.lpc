#include <std.h>
#include <amun.h>
inherit GUILDOBJ"spare_hall_rooms";
void create() {
    ::create();
    set_type("rogue");
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_short("Last Saints");
    set_long("%^BOLD%^%^RED%^Rogue Hall%^RESET%^\n%^BOLD%^%^BLACK%^This is the hall of the rogues. Rogues come here to train their skills, improve their stats, and advance in levels. There is a statue in the middle of the room.%^RESET%^");
    set_exits((["down" : GUILDROOM"bedrooms", "northeast" : GUILDROOM"level4_main"]));
    new(GUILDOBJ"rogue_statue")->move(this_object());
}
