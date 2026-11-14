#include "std.h"

/* Wizzes note: look at this file about how to make you own station.
It should define the two functions "look_arrive" and "look_depart" that
are called when the train arrives or departs from the station. The
players inside the train will get the messages describing this station.
Contact Deepthought via mail if you have a station ready and want it
to be included in the C.A.R.T. system. Tell him the name the station
should be called in the underground maps.
*/

TWO_EXIT("room/vill_shore2", "down",
	"room/beachstation2","east",
	 "C.A.R.T. Station (Beach)",
"You are standing on an elevated plateform. It's quite windy up here,\n"+
"as the sea is nearby. The rails coming from the west end at this point.\n"+
"Another platform is to the east. An iron staircase leads down.\n",1)

look_depart() {
	return "The train leaves the station westward towards the city.\n";
	}

look_arrive() {
	return "You arrive at an elevated station. The sea can be seen to the east.\n"+
	"The line ends here.\n";
	}

