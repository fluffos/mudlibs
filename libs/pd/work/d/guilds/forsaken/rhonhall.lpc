#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

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

    set_name("Hall of the Forsaken");
    set_long("You have entered Forsaken's secret hall in Rhondale. The carvings "
      " on the wall describle the life of the ancient Forsaken people living in "
      "Rhondale. There is a blue coldfire burning in the middle of the room. The fire "
      "is swirling and dancing as it forms enormous burning flames which vanish into "
      "nothingness.");
    set_items(([
	"carvings" : "Small carvings have been etched into the wooden walls, "
	"the carvings show the old ways of the Forsaken hunting techniques.", 
	"coldfire" : "This magical fire lights up the room, it seems to have nothing "
	"feeding it, yet burns so furiously.",
      ]));
    set_exits(([
	"out" : "/d/freepk/rhondale/rooms/zforest/x25y14",
	"south" : "/d/guilds/forsaken/rhonportal",
      ]));
}
