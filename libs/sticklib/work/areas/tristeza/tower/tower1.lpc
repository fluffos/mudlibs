#include <room.h>
#include <areas.h>
#include <generic_rooms.h>
#include <mud_name.h>

void create_room() {
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set(NO_PK);
    set_short(MUD_NAME " Tower (First Floor)");
    set_long(
      "This is the first floor of the "+MUD_NAME+" Tower. There doesn't seem to be\
 much in here, except for a hammer and saw lying on the floor.");
    set_exits(([
	"up"   : AREA_TRISTEZA+"tower/tower2",
	"down" : GENERIC_ROOM_ADV_GUILD,
      ]));
    replace_program(ROOM_FILE);
}
