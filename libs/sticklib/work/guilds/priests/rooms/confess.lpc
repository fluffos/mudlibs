#include "priest_room.h"

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT_TO);
    if(random(4)) set(PREVENT_TELEPORT_FROM);
    set(ROOM_WD, WD_INDOORS);
    set_short("The confession room");
    set_long(
      "This is the room where you can tell the priest your worries and your \
heinous deeds. You can't see the priest, but somehow you know that \
he can hear you anyway. Don't hesitate, tell him. He will listen."
    );
    add_exit("east",PRIEST_ROOM_DIR "hall");
    set(NO_PK);
    set(IN_CITY);

    replace_program(ROOM_FILE);
}
