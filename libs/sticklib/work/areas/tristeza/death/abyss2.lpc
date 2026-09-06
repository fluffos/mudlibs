/* Right Fist of the Golem */
/* The Abyss */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Abyss");
    set_long(
      "You are somewhere in the chaos of the Abyss. You could possibly travel \
to the northeast or southeast.");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([
	"northeast": AREA_TRISTEZA+"death/abyss4",
	"southeast": AREA_TRISTEZA+"death/abyss1"
      ]));
    add_monster(AREA_TRISTEZA+"death/right_fist", 0, 1);
    replace_program(ROOM_FILE);
}

