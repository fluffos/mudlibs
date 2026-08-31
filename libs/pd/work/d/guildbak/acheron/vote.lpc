#include <std.h>
#include <guild.h>
inherit VOTE;

void create() {
    ::create();
    set_name("Acheron Voter's Booth");
    set_long("%^BOLD%^%^BLUE%^This is not a very big room, a couple of "
      "boths stand either "
      "side of the room and a small box with a slit for where to place your "
      "vote to be counted. A calming dim candle above the box is the only "
      "source of light in this room and some vents in the walls bring in "
      "fresh air to clear you mind for when you need to vote.  There is a "
      "sign showing the list of commands.");
    set_short("Acheron Voter's Booth");
    set_guild("acheron");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1,
	"no teleport" : 1,
      ]) );
    set_exits(([
	"down": ACHERON"hall",
      ]));
}
