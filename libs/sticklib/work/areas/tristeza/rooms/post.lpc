#include <room.h>
#include <areas.h>
#include <generic_items.h>
#include <city_name.h>

void
create_room()
{
    set_short("Post Office");
    set_long(
      "Welcome to the NEW " CITY_NAME " Post Office -- Here you can send and\
 receive all of your mud mail.  Please type <help mailbox> for a list\
 of commands and their usages.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set(NO_PK);
    set(PREVENT_TELEPORT);
    set_exits(([ "southeast" : AREA_TRISTEZA+"virtual/S6_6" ]));
    add_object(GENERIC_MAILBOX, 0, 1);
}
