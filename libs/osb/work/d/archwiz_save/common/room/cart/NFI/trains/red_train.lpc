/*
 *	A C.A.R.T. underground train.
 *	red line
 */

#define COLOR "red"
#define ALIAS "train"

#include "trains/trainn.h"

buildnames() {
	stationnames = ({
		"players/snooze/station",
		"room/station",
		"players/carsten/room/station",
		"room/mine/tunnel13"
		});
	numstations = sizeof(stationnames);
	}

get_direction(nr) {
	if (nr < numstations)
		return "Mine";
	else
		return "Glastonbury";
	}

get_stationlist() {
	return "--- C.A.R.T. RED LINE ---\n"+
                "Glastonbury - Central Station - Crazy Castle - Mine\n";
	}
