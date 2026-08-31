//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("unholy");
    set_name("Guild Treasury");
    set_long("%^BOLD%^Extremely durable rock has been hit here.  It appears "
      "virtually impossible to dig any further in this direction.  This is "
      "now the unholy's treasury, very protected.");
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));
    set_items(([ "inscription" : "It's a sign you can read."]));
    set_short("Guild Treasury");
    set_exits(([
	"west" : ROOMS"unholy/hall",
      ]));
}
