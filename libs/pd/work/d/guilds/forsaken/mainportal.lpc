#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
    set_name("forsaken Portal Room");
    set_short("Forsaken Portal Room");
    set_long("The room you have entered seems to drop away from reality "
      "as you enter. Surrounding you, a tunnel of black fire twists and swirls, "
      "forming and dissipating as it whirls around you. The fire seems to be drawn "
      "towards the centre of the room, where it changes from black chaos to the huge "
      "form of a fanged wolf skull. The fiery skull rages as it opens wide, "
      "a deep red glow shows forth from inside.");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );


    set_exits( (["up" : ROOMS"forsaken/room1", ]) );

}
