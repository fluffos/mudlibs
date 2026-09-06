#include <room.h>
#include <areas.h>
#include <mud_name.h>

void
create_room()
{
    set_short(MUD_NAME+" Tower (Third Floor)");
    set_long("You are now on the third floor of " MUD_NAME " tower.\
 Sadly, this seems to be the highest floor of the tower you cam see;\
 the tower seems to be under construction, and you can only return\
 back down the stairs. Some day this huge tower will be ready.");
    set(NO_PK);
    set(IN_CITY);
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_exits(([ "down" : AREA_TRISTEZA+"tower/tower2" ]));
    //	replace_program(ROOM_FILE);
}


int query_is_start_location() { return 1; }
