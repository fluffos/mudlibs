/*
 *	A C.A.R.T. underground train.
 *	blue line
 */

#define COLOR "blue"
#define ALIAS "train"

#include "trains/trainn.h"

buildnames() {
	stationnames = ({
		"room/eaststation",
		"room/beachstation2"
		});
	numstations = sizeof(stationnames);
	}

get_direction(nr) {
	if (nr < numstations)
		return "Beach";
	else
		return "Sun Alley";
	}

get_stationlist() {
	return "--- C.A.R.T. BLUE LINE ---\n"+
                "Sun Alley - Beach\n";
	}
