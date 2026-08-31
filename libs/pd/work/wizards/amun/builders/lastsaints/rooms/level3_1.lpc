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
    set("long", "%^BOLD%^%^WHITE%^%^%^BOLD%^%^WHITE%^This room is full of open windows allowing the sky to shine through. Marble columns line the wall opposite the windows allowing the light, whether night or day, to shine upon them. All around the sounds of hustle and bustle can be heard from the shops.%^RESET%^");
    set_exits( ([  "north" : GUILDROOM+"level3_main" ]) );
}
