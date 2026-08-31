//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("forsaken");
    set_name("Forsaken Treasury");
    set_long("The treasury is gaudily decorated with trophys won in battle.  "
      "Severed heads of monsters from faraway lands line the walls.  On the "
      "far wall lies the head of an enormous black dragon, though dead its "
      "ferocity it portrayed in life still echos in its glazed eyes.  There "
      "is an obsidian plaque near the head with golden lettering inscribed "
      "upon it.  For a list of commands please %^BOLD%^%^BLUE%^<read sign>%^RESET%^");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

    set_items(([ "heads" : "These gruesome heads are mounted as trophies." ]));
    set_short("Forsaken Treasury");
    set_exits(([
	"west" : ROOMS"forsaken/hall",
      ]));
}

