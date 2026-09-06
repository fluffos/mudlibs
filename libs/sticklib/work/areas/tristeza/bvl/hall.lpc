#include <room.h>
#include <areas.h>
#include <generic_items.h>

void
create_room()
{
    set_short("Hall");
    set_long(
      "This is the headquarters of the Brotherhood vs. Lords. All those\
 who hate Lords and want to get rid of them are welcome here.\
 No Lord can summon anyone from this place.");
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_exits(([
	"west" : AREA_TRISTEZA+"bvl/lobby",
	"east" : AREA_TRISTEZA+"bvl/inner"
      ]));
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "bvl_board", 0 }),
      }), 0, 1);
    replace_program(ROOM_FILE);
}
