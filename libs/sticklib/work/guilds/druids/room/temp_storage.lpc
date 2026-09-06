#include <room.h>
#include <areas.h>

void
create_room()
{
	set_short("Workroom");
	set_long(
"This is a standard workroom. You do not usually see any of these, except\
 with new coders. Even the desk is empty. There is a note on the wall."
 );

	set_items(([
		"note" : "This is a workroom of a new coder.",
		"desk" : "It is empty."
	]));

	set_exits(([
		"church" : "/room/church",
                "guild" : AREA_TRISTEZA "adv_guild/adv_guild",
                "lpub" : AREA_TRISTEZA "shops/lords_pub",
                "post" : AREA_TRISTEZA "rooms/post"
	]));

	set_outdoors(WD_INDOORS);
	set_light_level(LT_BRIGHT);
}
