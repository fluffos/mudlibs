/* Death's rooms */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Planar Wormhole");
    set_long(
      "You are in a planar wormhole, a tunnel through the boundaries of\
 time and space. At this point of the tunnel you can choose the\
 direction, but you know that safe return is not assured.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);

    set_exits(([
	"north" : AREA_TRISTEZA+"death/winding",
	"south" : AREA_TRISTEZA+"death/astral_plane"
      ]));
    replace_program(ROOM_FILE);
}
