#include <room.h>
#include <areas.h>
#include <mud_name.h>

void
create_room()
{
    set_short(MUD_NAME " Tower (Second Floor)");
    set_long(
      "This second floor of " MUD_NAME " Tower has large windows on every wall,\
 so you can see far away to the lands of " MUD_NAME ". Far to the north,\
 beyond plains the mountains rise towards skies. To the northwest, even\
 farther away, is the land of Kaleva. To the east you can see the harbour\
 and the sea. North of the sea (that is, northeast from here) grows a vast\
 forest. Westwards is a great forest. To the south is the unexplored\
 wilderness, into which only few paths or roads go.");
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(IN_CITY);
    set_exits(([
	"up"	: AREA_TRISTEZA+"tower/tower3",
	/* Was:
			"down"	: AREA_TRISTEZA+"tower/tower1"
	Is: */
	"down"	: AREA_TRISTEZA+"adv_guild/skill_room"
      ]));
    replace_program(ROOM_FILE);
}
