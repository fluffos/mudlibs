#include "std.h"

/* Wizzes note: look at this file about how to make you own station.
It should define the two functions "look_arrive" and "look_depart" that
are called when the train arrives or departs from the station. The
players inside the train will get the messages describing this station.
Contact Deepthought via mail if you have a station ready and want it
to be included in the C.A.R.T. system. Tell him the name the station
should be called in the underground maps.
*/

ONE_EXIT("room/eastroad3", "up",
	 "C.A.R.T. Station Sun Alley",
"You are in an underground station of the C.A.R.T. The walls are tiled\n"+
"in all coulors and glowing yellow balls emit a soft light. Plants add\n"+
"to the comforable atmosphere of this place. Escalators lead up to the\n"+
"street.\n",1)

look_depart() {
	return "The train leaves the station and rolls into darkness again.\n";
	}

look_arrive() {
	return "Light floods in as the train arrives at a colorfull station.\n"+
	"A sign reads: East Road/Sun Alley.\n";
	}

