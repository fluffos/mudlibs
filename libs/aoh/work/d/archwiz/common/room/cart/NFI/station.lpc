#include "std.h"

/* Wizzes note: look at this file about how to make you own station.
It should define the two functions "look_arrive" and "look_depart" that
are called when the train arrives or departs from the station. The
players inside the train will get the messages describing this station.
Contact Deepthought via mail if you have a station ready and want it
to be included in the C.A.R.T. system. Tell him the name the station
should be called in the underground maps.
*/

#undef EXTRA_RESET
#define EXTRA_RESET\
        if (!present("transit map")) {\
            object map;\
	    map = clone_object("obj/treasure");\
	    move_object(map, "room/station");\
	    call_other(map, "set_id", "transit map");\
	    call_other(map, "set_alias", "map");\
		call_other(map, "set_short", "C.A.R.T. transit map");\
		call_other(map, "set_long", buildmapcontents());\
		call_other(map, "set_read", buildmapcontents());\
	    call_other(map, "set_weight", 1);\
	    call_other(map, "set_value", 5);\
        }

buildmapcontents() {
	return
		call_other("room/trains/yellow_train", "get_stationlist") +
		call_other("room/trains/red_train", "get_stationlist") +
		call_other("room/trains/blue_train", "get_stationlist");
	}

ONE_EXIT("room/vill_green", "up",
	 "Main Station",
"This is Main Station, the central point of the C.A.R.T. underground\n"+
"system. Several lines run through this station. The hall is brightly\n"+
"lit by large light balls hovering magically under the ceiling.\n"+
"Escalators lead up to Central Plaza.\n",1)

look_depart() {
	return "The train is leaving Central Station and entering a dark tunnel.\n";
	}

look_arrive() {
	return "Light bursts in as the train arrives at Central Station, a large\n"+
		"excavated hall.\n";
	}

