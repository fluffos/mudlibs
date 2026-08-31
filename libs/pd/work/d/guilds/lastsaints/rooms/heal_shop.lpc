#include <std.h>
#include <amun.h>
#include <guild.h>
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
    set_short("Saints Healing Shop");
    set_long("%^BOLD%^%^YELLOW%^Last Saints Healing Shop%^RESET%^\n"
      "%^BOLD%^%^WHITE%^This is a place for you to get things for your healing needs.  Il Duce has a sign posted on the wall for all to read.%^RESET%^");
    set_items( ([ "shop": "This is a place for you to sell your armour and get money for your travels." ]) );
    set_exits( ([ "east" : GUILDROOM+"level3_main" ]) );
}
void reset() {
    ::reset();
    if(!present("duce")) 
	new(GUILDMOB+"duce")->move(this_object());
}
