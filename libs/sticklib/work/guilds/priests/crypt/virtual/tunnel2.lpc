#include <room.h>
#include <guild.h>
#include "../DEFS.h"

void create_room()
{
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_INDOORS);
    set_short("An old tunnel");
    set_long("You are in a dusty old tunnel somewhere under the cathedral. \
In the south the tunnel seems to end, and in the north the tunnel branches \
into many smaller tunnels.");
    set_exits(([
	"north" : ROOM_DIR "maze_1",
	"south" : ROOM_DIR "tunnel1",
      ]));
}
