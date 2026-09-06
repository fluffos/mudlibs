#include <room.h>

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(IN_CITY);
    set_short("The local prison");
    set_long("You are in the local prison.");
    set_commands(([ "quit" : "quit" ]));
}

status
quit()
{
    return 1;
}
