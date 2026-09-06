/* Left Fist of the Golem */
/* The Abyss */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Abyss");
    set_long(
      "You are somewhere in the chaos of the Abyss. You could possibly travel \
to the northwest or southwest.");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([
	"northwest": AREA_TRISTEZA+"death/abyss4",
	"southwest": AREA_TRISTEZA+"death/abyss1"
      ]));
    add_monster(AREA_TRISTEZA+"death/left_fist", 0, 1);
    replace_program(ROOM_FILE);
}
