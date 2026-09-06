#include <room.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("Corridor");
    set_long("You are in a north-south passage in the Finnish Club. To the\
 north is the hall, and to the south is the dressing room of the sauna.");
    set_exits(([
	"north"	: CITY_PATH+"finnclub/hall",
	"south"	: CITY_PATH+"finnclub/dressing"
      ]));
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(NO_PK);
    set(IN_CITY);
    replace_program(ROOM_FILE);
}
