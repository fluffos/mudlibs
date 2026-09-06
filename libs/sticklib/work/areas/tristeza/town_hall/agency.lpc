#include <room.h>
#include <mud_name.h>

#include <generic_items.h>
#include "DEFS.h"

void
create_room()
{
    set(IN_CITY);
    set(NO_PK);
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Travel Agency");
    set_long(
      "This is your local travel agency. Here you can get information about different\
 locations in "+MUD_NAME+".  There are some colorful posters on the wall, but the\
 only item here that catches your interest is an advertisement board.");
    set_exits(([ "south": THALL_ROOMS "hall" ]));
    set_items(([
	({"poster","posters","colourful posters"}) :
	"They are just some old colourful posters."
      ]));

    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "travel_agency_board", 0 }),
      }), 0, 1);
    replace_program(ROOM_FILE);
}
