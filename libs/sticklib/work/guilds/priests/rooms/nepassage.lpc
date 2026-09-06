#include "priest_room.h"
#include <guild.h>

void create_room()
{
    set_light(LT_LIGHTS);
    if(random(3)) set(PREVENT_TELEPORT);
    set(ROOM_GUILD);
    set_outdoors(WD_INDOORS);
    set_short("A small passageway northeast of the altar");
    set_long(
      "This passageway is extremely spartan, with cold unadorned marble "
      "floors, and an extremely tall ceiling that vanishes into mist. ");
    add_exit("southwest",PRIEST_ROOM_DIR+"hallway");
    add_exit("north",PRIEST_ROOM_DIR+"passage3");
    set(IN_CITY);
    replace_program(ROOM_FILE);
}
