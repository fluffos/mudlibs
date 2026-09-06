/* Death's rooms */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Dark winding corridor");
    set_long(
      "You feel that this dark windy east-west corridor is filled with ultimate \
terror. You make a mistake by looking at the floor; the material is not \
stone but souls! You can see thousands of faces with the expression of \
immense anguish and pain melted into the floor. There is an archway \
to the north, and a strange glowing tunnel leads south.");
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([
	"east"  : AREA_TRISTEZA+"death/death_room",
	"west"  : AREA_TRISTEZA+"death/top_stairs",
	"north" : AREA_TRISTEZA+"death/ldw",
	"south" : AREA_TRISTEZA+"death/wormhole"
      ]));
}
