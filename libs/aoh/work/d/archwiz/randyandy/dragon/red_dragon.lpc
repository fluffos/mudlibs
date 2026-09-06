/* A flying dragon for the Nightfall Flightdragon Airways */

#define COLOR "red"
#define ALIAS "dragon"
#define SPEED 23

#include "/d/archwiz/randyandy/dragon/planevar.h"

buildnames() {
	stationnames = ({
	// BEGONE "/d/avalon/common/village/dragon_port",
	/*	"/d/avalon/common/ireland/forest/2G2", */
	// BEGONE "/d/atlantis/common/room/field/42,53",
	// BEGONE "/d/archwiz/common/room/city/airport2",
	});
	numstations = sizeof(stationnames);
}

get_direction(nr) {
	if (nr < numstations)
	     return "Nightfall City";
	else
	     return "England";
}

get_stationlist() {
	return "-- Nightfall Flightdragon Airways Red Line --\n"+
	       "currently flying: Nightfall City - Port Atlinten - England\n";
}

#include "/d/archwiz/randyandy/dragon/plane.h"

