#include "std.h"

/* Wizzes note: look at this file about how to make you own station.
It should define the two functions "look_arrive" and "look_depart" that
are called when the train arrives or departs from the station. The
players inside the train will get the messages describing this station.
Contact Deepthought via mail if you have a station ready and want it
to be included in the C.A.R.T. system. Tell him the name the station
should be called in the underground maps.
*/

ONE_EXIT("room/beachstation", "west",
	 "C.A.R.T. Station (Beach)",
"You are standing on an elevated plateform. It's quite windy up here,\n"+
"as the sea is nearby. The rails run north and south. Another platform is\n"+
"to the west.\n",1)

look_depart() {
	return "The train leaves the station. You have a wonderful view at the sea.\n";
	}

look_arrive() {
	return "You arrive at an elevated station. The sea can be seen to the east.\n";
	}

