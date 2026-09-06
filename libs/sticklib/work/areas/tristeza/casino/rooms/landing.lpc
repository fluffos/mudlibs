/*********************************************************************
 landing.c -  stairway landing 
*********************************************************************/

#include <room.h>
#include <door_defs.h>
#include "../casino.h"

void
create_room()
{
    set_short("Stairway landing.");
    set_long(
      "This is a dark stairway landing, from which a steep and narrow\
 stairway leads down into the darkness below.  The air here is\
 musty and somewhat stale, and you feel a vague sense of unease\
 as if you are tresspassing where you do not belong.");

    set_exits(([
	"down" : AREA_PATH+"rooms/storage"
      ]));

    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_DARKNESS);


    replace_program( ROOM_FILE );
}


