#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
    object board;
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
    set_long("Giving light to this grand room is a great pillar of blue fire. "
      "It dances in the middle of the room wildly being fueld by the air around you. "
      "Through a small window the town of Purgatory can be seen with is everlasting "
      "sounds of deranged childern playing and undead groans of the towns people.");
    set_exits(([
	"out" : "/d/freepk/purgatory/room/purgatory10"
      ]));
}
