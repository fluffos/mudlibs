#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a rocky hallway");
    set_short("A rocky hallway");
    set_long("A freshly dug hallway, carved into the stone of the mountain, "
      "contains a dark opening in a distance.  There are stairs leading "
      "back down to the heart of the guild.");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );


    set_exits( (["down" : "/d/guilds/dw/hall", "north" : "/d/guilds/dw/oilshop"]) );


    set_items( ([
	"hallway"  : "Large gouges in the rock line the hallway, they look almost like they were made by a dragons claws.",
	"stairs" : "These stairs lead back down into the heart of the guild.",
      ]) );

}
