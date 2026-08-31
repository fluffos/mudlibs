#include <guild.h>
#include <std.h>

inherit VOTE;

void create() {
    ::create();
    set_name("Dragon Warriors Voting Booth");
    set_short("Dragon Warriors Voting Booth");
    set_long("This is the Dragon Warriors' Voting Booth.  The room is "
      "in shambles, it appears a fight or two has broken out, and paper"
      " littering the floor like a thick carpet.  Voting is essential "
      "for all new guild ideas.  Please vote according to your heart, "
      "not by popular demands.  To view the commands for the booth "
      "<read sign>.");
    set_guild("DW");
    set_exits((["out":"/d/guilds/dw/hall"]));
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
}

