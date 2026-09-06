#include <room.h>
#include <guild.h>
#include "../DEFS.h"

void create_room()
{
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_INDOORS);
    set_short("An old tunnel");
    set_long("You are in a old damp tunnel somewhere under Tristeza.");
    set_exits(([
	"southwest" : ROOM_DIR "maze_" + N_ROOMS,
	"northeast" : ROOM_DIR "passage2",
      ]));
}
