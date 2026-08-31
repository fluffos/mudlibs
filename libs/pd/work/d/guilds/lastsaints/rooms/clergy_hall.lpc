#include <std.h>
#include <amun.h>
inherit HALL;
void create() {
    ::create();
    set_type("clergy");
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_short("Last Saints");
    set_long("%^BOLD%^%^RED%^Clergy Hall%^RESET%^\n%^BOLD%^%^BLACK%^This is the hall of the clergy. Clergies come here to train their skills, improve their stats, and advance in levels. There is a statue in the middle of the room.%^RESET%^");
    set_exits((["east" : GUILDROOM"level4_main"]));
    new(GUILDOBJ"clergy_statue")->move(this_object());
}
