#include <room.h>

#include <generic_items.h>
#include <generic_rooms.h>

void
create_room()
{
    set(IN_CITY);
    set(NO_PK);
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Continuing education room");
    set_long(
      "This is the center for continuing education. It is here that players \
may begin to break out of guilds and into skills. This will serve \
as a discussion room, and not a training room."
    );
    set_exits(([ "north": GENERIC_ROOM_ADV_GUILD ]));
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "skills_discussion_board", 0 }),
      }), 0, 1);
    replace_program(ROOM_FILE);
}
