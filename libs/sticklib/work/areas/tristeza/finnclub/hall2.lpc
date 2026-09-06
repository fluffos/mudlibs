#include <room.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("2nd Floor Hall");
    set_long("This is the hall in the second floor of the Finnish Club.\
 There is a stairway going down.");
    set_exits(([ "down" : CITY_PATH+"finnclub/hall" ]));
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    replace_program(ROOM_FILE);
}
