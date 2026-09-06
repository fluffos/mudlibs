#include <room.h>
#include <areas.h>
#include <city_name.h>

#include "DEFS.h"

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_OUTDOORS);
    set_short("Start room for the Practice area");
    set_long(
      "You are on an empty plain somewhere on the spherical Pancake - \
the world of " CITY_NAME ". This area is not meant for mortals, however, \
but coders and their testplayers, for practice and experimentation. \
Type 'more here' for more information.");

    set_exits(([
	"out": AREA_TRISTEZA + "virtual/S7_7",

	// Coders: if you make rooms, add your "exit" here:
	// use your own name to name the exit. For example:
	"graah": ROOMS_DIR + "adamant",
      ]));

    replace_program(ROOM_FILE);
}
