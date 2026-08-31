#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Darksoul Portal Room");
    set_short("Darksoul Portal Room");
    set_long("%^BOLD%^%^BLACK%^This is the portal room. Several of the souls captured by the "
      "%^BOLD%^%^BLACK%^Darksouls are used to carry its members from place to place. "
      "%^BOLD%^%^BLACK%^Be very careful when riding the souls, some are known to "
      "%^BOLD%^%^BLACK%^extract their revenge by misplacing its members.");
    set_properties(([
	"light"       : 2,
	"no magic"    : 1,
	"no teleport" : 1,
	"no bump"     : 1,
	"no steal"    : 1,
	"no attack"   : 1,
      ]));
    set_exits( (["south" : ROOMS"darksoul/hall", ]) );

}
