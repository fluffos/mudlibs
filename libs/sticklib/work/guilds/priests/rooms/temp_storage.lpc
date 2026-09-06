#include "priest_room.h"

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set_short("Temporary storage");
    set_long(
      "You are in a small and simple room, obviously used as some kind of storage."
    );
    set_exits(([
	"northwest" : PRIEST_ROOM_DIR "nave",
      ]));
    replace_program(ROOM_FILE);
}
