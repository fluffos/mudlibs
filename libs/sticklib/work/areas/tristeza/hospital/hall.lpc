#include <room.h>
#include <areas.h>
#include <city_name.h>

#include "../DEFS.h"

void reset_room();

void
create_room() {
    set_short("Hall");
    set_long(
      "You are in the hall of " CITY_NAME " Sanatorium. The doctor's workroom is "+
      "to the north, and the patients' hall to the south. You can exit this "+
      "place to the west.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_INDOORS);
    set(IN_CITY);
    set_exits(([
	"south" : AREA_TRISTEZA+"hospital/patient_hall",
	"north" : AREA_TRISTEZA+"hospital/doctors_room",
	"west"  : AREA_TRISTEZA+"virtual/S7_9"
      ]));
    set_commands(([ "north" : "north" ]));
    add_monster(AREA_TRISTEZA+"hospital/caretaker", "Caretaker arrives.",1);
}

status
north()
{
    object ct;
    if ( ct=present("caretaker", this_object()))
    { 
	if ((AREA_TRISTEZA+"hospital/doctors_room")->query_doctor_busy())
	{
	    this_player()->tell_me("The caretaker stops you.");
	    tell_here("The caretaker stops "+this_player()->query_name()+".",this_player());
	    tell_here(
	      "Caretaker says: The doctor is busy right now. Return later.");
	    if (this_player()->query_coder_level())
		tell_here("But, since you are a coder you may enter.");
	    else return 1;
	}
    }
    return 0;
}
