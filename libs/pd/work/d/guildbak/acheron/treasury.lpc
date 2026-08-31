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
    set_guild("acheron");
    set_name("Acheron's Treasury");
    set_short("Acheron's Treasury");
    set_long("%^BOLD%^%^BLUE%^Entering the private sanctum of the Acheron "
      "Treasury, there %^BOLD%^%^BLUE%^is large vault can be seen at the "
      "south end of the room. A %^BOLD%^%^BLUE%^list and a scroll have "
      "been pinned up on the wall, \n%^BOLD%^%^RED%^<read "
      "%^BOLD%^%^BLUE%^%^BOLD%^%^RED%^sign>%^BOLD%^%^BLUE%^ and "
      "%^BOLD%^%^RED%^<read scroll>%^BOLD%^%^BLUE%^ make them accessible.");
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
	"up" : "/d/guilds/acheron/hall",
      ]));
    set_items(([ "vault" : "Its a fairly large vault that looks to be "
	"impenetrable." ]));
}

