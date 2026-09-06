#include "priest_room.h"
#include <guild.h>

void create_room()
{
    set_light(LT_LIGHTS);
    set(ROOM_GUILD);
    if(random(3)) set(PREVENT_TELEPORT);
    set_outdoors(WD_INDOORS);
    set_short("A small marble passageway");
    set_long(
      "This passageway is extremely spartan, with cold unadorned marble "
      "floors, and an extremely tall ceiling that vanishes into mist. ");
    add_exit("south",PRIEST_ROOM_DIR+"nwpassage");
    add_exit("north",PRIEST_ROOM_DIR+"passage4");
    set(IN_CITY);
    replace_program(ROOM_FILE);
}
