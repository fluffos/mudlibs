#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Black cave");
    set_long(
      "This is a small black cave at the base of a narrow stone\
 stairway. The walls, floor and ceiling are totally black. The\
 sense of power nearly overwhelming! You sense powerful lines of\
 force converging to this place.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_NONE);
    set(IN_CITY);
    set(PREVENT_TELEPORT);
    set_exits(([ "up" : AREA_TRISTEZA+"rooms/door_trap2" ]));
    add_monster(AREA_TRISTEZA+"special/trapped_demon","You feel a surge of power!",1);
    replace_program(ROOM_FILE);
}

