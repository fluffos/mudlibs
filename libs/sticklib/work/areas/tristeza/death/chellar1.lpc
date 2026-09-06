/* Death's rooms */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Chellar");
    set_long("A terrible feeling of hopelessness makes you almost forgot\
 who you are. To the east, where this chellar continues, the hopelessness is\
 even stronger.");
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([
	"east"	: AREA_TRISTEZA+"death/chellar2",
	"west"	: AREA_TRISTEZA+"death/bottom_stairs"
      ]));
    replace_program(ROOM_FILE);
}
