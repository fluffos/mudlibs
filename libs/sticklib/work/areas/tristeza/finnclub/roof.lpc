#include <room.h>
#include <door_defs.h>
#include "../DEFS.h"


void
create_room()
{
    set_short("Roof of the Finnish Club");
    set_long("You are standing on the roof of the Finnish Club.");

    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set(NO_PK);

    add_object( ({ DOOR_FILE,
	({ "add_door",
	  "It is just a trapdoor.",
	  "down", CITY_PATH+"finnclub/hall2", 0,
	  0, 1, 0, 0, 160,
	  "It is extremely complex, if not impossible, to pick!" })
      }) , 0, 0 );

    replace_program(ROOM_FILE);
}
