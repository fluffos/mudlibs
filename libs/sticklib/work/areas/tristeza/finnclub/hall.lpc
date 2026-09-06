#include <room.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("Hall");
    set_long(
      "This is the hall of the Finnish Club. To the east is 'Sesto' (shop), to \
the west is the \"K-Kauppa\" (a shop), to the south is the dressing room \
of the Sauna, and to the southwest, 'Kirjasto' (library). You can exit the \
Finnish Club to the north, but remember that Portsari will charge you \
money each time you re-enter.");

    set_exits(([
	"north"	    : CITY_PATH+"finnclub/foyer",
	"east"	    : CITY_PATH+"finnclub/shop",
	"south"	    : CITY_PATH+"finnclub/dressing",
	"southwest" : CITY_PATH+"finnclub/library",
	"west"	    : CITY_PATH+"finnclub/k-kauppa"
      ]));

    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    add_command("east", "east_cmd");
}

status
east_cmd()
{
    this_player()->tell_me("Sorry, but Sesto went bankrupt. There is \
a \"K-Kauppa\" to the west, which now sells the things.");
    return 1;
}
