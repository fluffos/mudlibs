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
    set("short", "Portal Room");
    set("long","%^BOLD%^%^WHITE%^In the center of the room stands the portal of the Last Saints. Look it over to see where it is you want to enter.\n");
    set_exits( ([ "west" : GUILDROOM+"level2_3" ]) );
    new(GUILDOBJ+"portal")->move(this_object());
}
