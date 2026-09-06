#include "priest_room.h"

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD,WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_short("The first floor of the Cathedral bell tower.");
    set_long(
      "The first floor of the cathedral bell tower is paneled exclusively "
      "in bird's eye maple, polished to a rich hue.  The steps are done "
      "in black and white marble, with a vein of gray.  The belltower has "
      "not functioned in its old capacity for years, and the room at the "
      "top has been renovated to allow the Council to meet there. Many strange "
      "rumours and legends abound about the bell tower, and it is clear that it "
      "is much larger seen from the outside than this simple stairway would "
      "suggest. ");
    set_exits(([
	"down" : PRIEST_ROOM_DIR "relaxation",
	"up" : PRIEST_ROOM_DIR "2tower"
      ]));
    replace_program(ROOM_FILE);
}


