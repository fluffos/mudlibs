#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );


    set_guild("DW");
    set_name("Dragon Warrior's Guild Treasury");
    set_long("Little piles of cobwebbed gold sits on a dusty floor.  "
      "A chained up goblin strains to get in front of the gold, to "
      "protect it from looters.  A sign stands on the ground with a "
      "list of commands availible.");
    set_short("Dragon Warrior's Guild Treasury");
    set_exits((["north":ALL"dw/hall"]));
}

