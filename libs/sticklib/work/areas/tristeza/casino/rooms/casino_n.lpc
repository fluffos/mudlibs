/*********************************************************************
 casino_n.c - Door to landing 
*********************************************************************/

#include <room.h>
#include <door_defs.h>
#include "../casino.h"

void
create_room()
{
    set_short("Joker's casino, stairway landing.");
    set_long(
      "This is the northern end of the gambling hall, which spreads\
 out to the south like a hive of bustling activity.  To the north\
 a dimly lit stairway leads upwards.");

    set_exits(([
	"up"       : AREA_PATH+"rooms/upstairs",
	"east"     : AREA_PATH+"rooms/casino_ne",
	"south"    : AREA_PATH+"rooms/casino_nc",
	"west"     : AREA_PATH+"rooms/casino_nw"
      ]));

    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    /** The door is here to prevent the masses    **/
    /** from getting to the wheel of misfortune.  **/
    /** The key is really hard to get, and the    **/
    /** lock is hard to pick (but not impossible) **/
    /** the same as a rich player home.           **/

    add_object( ({ DOOR_FILE,
	({ "add_door",
	  "It is a strong-looking door, intended for use by casino employees.",
	  "north", AREA_PATH+"rooms/landing", "quite complex",
	  "casino_storage_key", 1,1,1,165,
	  "It is quite complex, and may prove difficult to pick." })
      }) , 0, 0 );


    replace_program( ROOM_FILE );
}

