/*
 *	A C.A.R.T. underground train.
 *	yellow line
 */

#define COLOR "yellow"
#define ALIAS "train"

#include "trains/trainn.h"

buildnames() {
	stationnames = ({
		"room/south/sshore27",
		"room/forest12",
		"room/orc_vall",
		"room/station",
		"room/beachstation"
		});
	numstations = sizeof(stationnames);
	}

get_direction(nr) {
	if (nr < numstations)
		return "Beach";
	else
		return "Crescent Lake";
	}

get_stationlist() {
	return "--- C.A.R.T. YELLOW LINE ---\n"+
		"Crescent Lake - Mirkwood Forest - Orc Valley - Central Station - Beach\n";
	}
