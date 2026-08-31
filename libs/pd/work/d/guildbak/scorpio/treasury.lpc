//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("scorpio");
    set_name("Guild Treasury");
    set_long("The walls are lined with silver and gold.  The light "
      "from overhead shines on the marble floor causing a glare to "
      "be throughout the room.  A bloody sign is posted on the wall "
      "along with a scroll beside it.  %^BOLD%^%^BLUE%^<read sign>"
      "%^RESET%^ for a list of commands.");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


    set_short("Guild Treasury");
    set_exits(([
        "down": SCORPIO"lounge",
	"north": ALL"scorpio/hall",
      ]));
}

