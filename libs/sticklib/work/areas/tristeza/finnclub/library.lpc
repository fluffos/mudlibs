#include <room.h>
#include <generic_items.h>

#include "../DEFS.h"

void
create_room()
{
    set_short("Kirjasto");
    set_long("In this 'Kirjasto' (library) you will find information about\
 Finnish \"culture\" and language. There is not much stuff here yet.");
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);

    set_exits(([ "northeast" : CITY_PATH+"finnclub/hall" ]));

    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "finnclub_board", 0 }),
      }), 0, 1);
    replace_program(ROOM_FILE);
}
