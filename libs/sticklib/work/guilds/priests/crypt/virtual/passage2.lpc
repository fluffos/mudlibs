#include <room.h>
#include <guild.h>
#include "../DEFS.h"

void create_room()
{
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_INDOORS);
    set_short("An old tunnel");
    set_long("You are in an old tunnel somewhere under Tristeza. In the \
northeast there seems to be a ladder leading up.");
    set_exits(([
	"southwest" : ROOM_DIR "passage1",
	"northeast" : ROOM_DIR "under_tower",
      ]));
}
