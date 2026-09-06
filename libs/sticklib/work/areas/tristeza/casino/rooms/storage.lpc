/*********************************************************************
 storage.c - casino storage room 
*********************************************************************/

#include <room.h>
#include "../casino.h"

void
create_room()
{
    set_short("Casino storage basement.");
    set_long(
      "You have entered a dark and gloomy storage room in the basement\
 of the casino.  The thin layer of dust on the floor suggests that\
 this room is seldom visited.  In fact, you suspect that nobody has\
 been here in ages.  A quick glance around the room reveals nothing\
 of interest other than a large stone wheel pushed up against\
 the far wall.");

    set_exits(([
	"up" : AREA_PATH+"rooms/landing"
      ]));


    set_items(([
	"symbols" : "The symbols are incomprehensible.",
      ]));


    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_DARKNESS);

    add_permanent(AREA_PATH+"objects/misfortune" );

    replace_program( ROOM_FILE );
}


