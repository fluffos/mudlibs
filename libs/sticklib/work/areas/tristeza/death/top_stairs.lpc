/* Death's rooms */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Top of stairs");
    set_long(
      "You are standing on a top of spiral staircase. To the east goes a dark\
 winding corridor, from which you can sense the strongest fear and pain\
 you have ever felt.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([
	"east" : AREA_TRISTEZA+"death/winding",
	"down" : AREA_TRISTEZA+"death/bottom_stairs"
      ]));
    replace_program(ROOM_FILE);
}
