#include "priest_room.h"
#include <guild.h>
void create_room()
{
    set_light(LT_LIGHTS);
    set(ROOM_GUILD);
    set_outdoors(WD_INDOORS);
    set_short("The back staircase");
    set_long(
      "This stairway is done in rich burl oak panelling. The steps are of "
      "some sort of clear quartz, with herbs seemingly imprisoned within it. "
      "You smell some sort of delicious odor coming up from below. "); 
    add_exit("southwest", PRIEST_ROOM_DIR+"nave");
    add_exit("down",PRIEST_ROOM_DIR+"wine_cellar");
    set(PREVENT_TELEPORT);
    replace_program(ROOM_FILE);
}
