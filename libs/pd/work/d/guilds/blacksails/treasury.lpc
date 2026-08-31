//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("blacksails");
    set_name("Hold of the Black Trident");
    set_short("Hold of the Black Trident");
    set_long("%^BOLD%^%^BLACK%^The hold of the ship, the very bottom of the vessel. This is where all the pirate's loot is kept. Piles of gold and gems cover the floor A few chests are lined up against the wall, holding trinkets and other valubales. A large scroll has been nailed to the wall, detailing every last coin that has been put down here.%^RESET%^"
    );
    set_exits(([
	"up":BLACKSAILS"hall",
        "west":BLACKSAILS"bow",
      ]));
    set_properties(([
	"light":1,
	"night light":1,
	"no teleport":1,
	"no kill":1,
	"no bump":1,
	"no steal":1,
        "indoors":1,
      ]));
  set_smell("default", "The room smells like seawater and metal.");

  set_listen("default", "Theboards creak and groan under the pressure of the water..");
}

