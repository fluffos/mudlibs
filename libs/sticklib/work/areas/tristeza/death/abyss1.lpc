/* The Abyss */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Abyss");
    set_long(
      "The swirling chaos abound this gray, dark plane prevents you from moving \
into any direction except northeast and northwest.");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(PREVENT_TELEPORT_TO);
    set_exits(([
	"northeast": AREA_TRISTEZA+"death/abyss3",
	"northwest": AREA_TRISTEZA+"death/abyss2"
      ]));
    replace_program(ROOM_FILE);
}

