//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("chosen");
    set_name("Main Guild hall of The Chosen");
    set_short("Main Guild hall of the Chosen");
    set_long("This is the Treasury of The Chosen.\nThere are "
      "some windows on each wall which are letting in "
      "some light from out side. A large diamond rests "
      "on a pedestal in the middle of the room. "
      "The light coming into the room looks to be "
      "refracting though the diamond, causing a rainbow "
      "to dance about the room. There is alot "
      "of light coming from the room to the west. "
      "A list of directions is posted on a sign.");
    set_exits(([
	"west":CHOSEN"hall",
      ]));
    set_properties(([
	"light":1,
	"night light":1,
	"no teleport":1,
	"no kill":1,
	"no bump":1,
	"no steal":1,
      ]));
}

