/* The Great Golem */
/* The Abyss */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Abyss");
    set_long(
      "The swirling chaos abound this gray, dark plane prevents your way into \
every direction except southeast and southwest. There is some kind of \
a building to the north.");
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_DIM);
    set_exits(([
	"north"    : AREA_TRISTEZA+"death/abyss5",
	"southeast": AREA_TRISTEZA+"death/abyss3",
	"southwest": AREA_TRISTEZA+"death/abyss2"
      ]));
    add_monster(AREA_TRISTEZA+"death/golem", 0, 1);
    replace_program(ROOM_FILE);
}
