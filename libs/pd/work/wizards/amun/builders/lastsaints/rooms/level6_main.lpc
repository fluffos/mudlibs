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
    set("long", "%^BOLD%^%^WHITE%^The sixth floor of the Last Saints is very quiet. All of tirun can be see from up here. There is a chest for all members use in the middle of the floor.%^RESET%^");
    set_exits( ([ "down" : GUILDROOM+"level5_main" ]) );
    new(GUILDOBJ"casket")->move(this_object());
}
