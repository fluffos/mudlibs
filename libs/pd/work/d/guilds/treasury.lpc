//  Coded by a Nutcase
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>
#include <money.h>
#include <treasury.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("The Guilds");
    set_name("Main Treasury");
    set_short("The Guild's Treasury");
    set_long("The room here is quite large and fancy.  Several golden tapestries "
      "line the walls, depicting various events in history.  A small sign "
      "next to a sphere on the ground.  <read sign> for help on using "
      "the commands.");
    set_properties(([
	"light"       : 2, 
	"night light" : 2, 
	"no teleport" : 1, 
	"no attack"   : 1,  
	"no magic"    : 1,
	"no bump"     : 1,
	"no steal"    : 1,
	"indoors"     : 1,
      ]));
    set_exits(([
	"south" : "/d/guilds/meeting",
      ]));
    set_items(([ "vault" : "Its a fairly large vault that looks to be "
	"impenetrable." ]));
}

