#include <room.h>
#include <areas.h>

void
create_room() 
{
    set_short("Inner Hall");
    set_long("You are in the inner hall of the Brotherhood.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_exits(([ "west" : AREA_TRISTEZA+"bvl/hall" ]));
    replace_program(ROOM_FILE);
}
