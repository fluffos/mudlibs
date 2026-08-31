#include <std.h>
#include <amun.h>
inherit HALL;
void create() {
    ::create();
    set_type("wanderer");
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_short("Last Saints");
    set_long("%^BOLD%^%^RED%^Wanderer Hall%^RESET%^\n%^BOLD%^%^BLACK%^This is the hall of the wanderers. Wanderers come here to train their skills, improve their stats, and advance in levels. There is a statue in the middle of the room.%^RESET%^");
    set_exits((["south" : GUILDROOM"level4_main"]));
    new(GUILDOBJ"wanderer_statue")->move(this_object());
}
